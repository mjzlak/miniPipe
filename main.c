/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:58:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/19 18:46:32 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

// Execute the commands in the linked list
static int	exec_commands(t_cmd *cmd, char **env)
{
	char	*absolute_path;

	if (!cmd || !cmd->cmd || !cmd->cmd[0])
		return (0);
	absolute_path = get_absolute_path(cmd->cmd[0], env);
	if (!absolute_path)
		return (perror_and_return("exec_commands: get_absolute_path:", 0));
	execve(absolute_path, cmd->cmd, env);
	perror("exec_commands: execve failed !");
	free(absolute_path);
	return (0);
}

// Fork a process, redirect the input and output and execute the command
static int	fork_process(t_cmd *line, char **env, int fd, int pipe_fd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (perror_and_return("fork_process: fork failed !", 0));
	if (pid == 0)
	{
		if (dup2(fd, STDIN_FILENO) == -1 || dup2(pipe_fd, STDOUT_FILENO) == -1)
			return (perror_and_return("fork_process: dup2:", 0));
		close(fd);
		close(pipe_fd);
		if (!exec_commands(line, env))
			return (0);
	}
	return (1);
}

// Open the input file, create pipes and call fork_process for each command
static int	pipex_launcher(t_cmd *line, char **env, int *fd, int *pipe_fd)
{
	if (!line || !line->infile || !line->infile[0])
		return (0);
	fd[0] = open(line->infile, O_RDONLY);
	if (fd[0] < 0)
		return (close_and_return(fd, pipe_fd, 0, "pipex_launcher: open:"));
	while (line->next)
	{
		if (pipe(pipe_fd) == -1)
			return (close_and_return(fd, pipe_fd, 0, "pipex_launcher: pipe:"));
		if (!fork_process(line, env, fd[0], pipe_fd[1]))
			return (close_and_return(fd, pipe_fd, 0, NULL));
		close(pipe_fd[1]);
		fd[0] = pipe_fd[0];
		pipe_fd[0] = -1;
		line = line->next;
	}
	fd[1] = open(line->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
		return (close_and_return(fd, pipe_fd, 0, "pipex_launcher: open:"));
	if (!fork_process(line, env, fd[0], fd[1]))
		return (close_and_return(fd, pipe_fd, 0, NULL));
	return (close_and_return(fd, pipe_fd, 1, NULL));
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*line;
	int		fd[3];
	int		pipe_fd[3];
	int		i;

	i = 0;
	while (i < 3)
	{
		fd[i] = -1;
		pipe_fd[i] = -1;
		i++;
	}
	if (!error_handling(argc, argv, env))
		return (-1);
	line = init_lst(argv, argc, 2);
	if (!line)
		return (-1);
	if (!pipex_launcher(line, env, fd, pipe_fd))
		return (-1);
	free_cmd_lst(line);
	return (0);
}
