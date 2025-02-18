/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:58:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/13 18:39:21mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

static int	exec_commands(t_cmd *cmd, char **env)
{
	char	*absolute_path;

	if (!cmd || !cmd->cmd || !cmd->cmd[0])
		return (0);
	absolute_path = get_absolute_path(cmd->cmd[0], env);
	if (!absolute_path)
		return (perror_and_return("exec_commands: get_absolute_path failed !", 0));
	execve(absolute_path, cmd->cmd, env);
	perror("exec_commands: execve failed !");
	free(absolute_path);
	return (0);
}

static int	fork_process(t_cmd *line, char **env, int *fd, int *pipe_fd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (perror_and_return("fork_process: fork failed !", 0));
	if (pid == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return (perror_and_return("fork_process: dup2 failed !", 0));
		if (pipe_fd)
		{
			if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
				return (perror_and_return("fork_process: dup2 failed !", 0));
		}
		else
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				return (perror_and_return("fork_process: dup2 failed !", 0));
		}
		close_all_opened_files(fd, pipe_fd, NULL);
		if (!exec_commands(line, env))
			return (0);
	}
	//waitpid(pid, NULL, 0);
	while (wait(NULL) > 0)
		;
	return (1);
}

static int	pipex_launcher(t_cmd *line, char **env, int nb_of_cmd)
{
	t_cmd	*last;
	int		fd[2];
	int		pipe_fd[nb_of_cmd];

	last = line;
	while (last->next)
		last = last->next;
	if (!line || !line->infile[0] || !last->outfile[0])
		return (0);
	fd[0] = open(line->infile, O_RDONLY);
	if (fd[0] < 0)
		return (close_and_return(fd, pipe_fd, 0, "pipex_launcher : open failed ! :"));
	fd[1] = open(last->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
		return (close_and_return(fd, pipe_fd, 0, "pipex_launcher : open failed ! :"));
	while (nb_of_cmd > 2)
	{
		if (pipe(pipe_fd) == -1)
			return (close_and_return(fd, pipe_fd, 0, "pipex_launcher : pipe failed ! :"));
		if (!fork_process(line, env, fd, pipe_fd))
			return (close_and_return(fd, pipe_fd, 0, NULL));
		line = line->next;
		nb_of_cmd--;
	}
	if (!fork_process(line, env, fd, NULL))
		return (close_and_return(fd, pipe_fd, 0, NULL));
	return (close_and_return(fd, pipe_fd, 1, NULL));
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*line;

	if (!error_handling(argc, argv, env))
		return (-1);
	line = init_lst(argv, argc, 2);
	if (!line)
		return (-1);
	if (!pipex_launcher(line, env, argc - 3))
		return (-1);
	free_cmd_lst(line);
	return (0);
}
