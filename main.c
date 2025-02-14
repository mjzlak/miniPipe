/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:58:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/13 18:39:21 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

static int	exec_commands(t_cmd *line, char **env)
{
	int		i;
	char	*absolute_path;

	if (!line || !line->cmd || !line->cmd[0])
		return (0);
	__builtin_printf("exec_commands: line->cmd[0] = %s\n", line->cmd[0]);
	while (line)
	{
		i = 1;
		while (line->cmd[i])
		{
			__builtin_printf("exec_commands: line->next->cmd = %s\n", line->next->cmd[0]);
			__builtin_printf("exec_commands: line->next->cmd[%d] = %s\n", i, line->next->cmd[i]);
			absolute_path = get_absolute_path(line->cmd[0], env);
			if (!absolute_path)
				return (0);
			__builtin_printf("exec_commands: absolute_path = %s\n", absolute_path);
			if(execve(absolute_path, line->cmd, env) < 0)
			{
				perror("execve failes");
				__builtin_printf("exec_commands: error from execve\n");
				return (0);
			}
			i++;
		}
		line = line->next;
	}
	return (1);
}

static int	fork_process(t_cmd *line, char **env, int *fd, int *pipe_fd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return (0);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			return (0);
		close(fd[0]);
		close(fd[1]);
		if (!exec_commands(line, env))
			return (0);
	}
	waitpid(pid, NULL, 0);
	return (1);
}

static int	pipex_launcher(t_cmd *line, char **env)
{
	t_cmd	*last;
	int		fd[2];
	int		pipe_fd[2];

	last = line;
	while (last->next)
		last = last->next;
	if (!line || !line->infile[0] || !last->outfile[0])
		return (0);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe failed !");
		close(fd[0]);
		close(fd[1]);
		return (0);
	}
	fd[0] = open(line->infile, O_RDONLY);
	if (fd[0] < 0)
		return (0);
	fd[1] = open(last->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
	{
		close(fd[0]);
		return (0);
	}
	if (!fork_process(line, env, fd, pipe_fd))
		return (0);
	if (!fork_process(last, env, pipe_fd, fd))
		return (0);
	close(fd[0]);
	close(fd[1]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*line;

	if (!error_handling(argc, argv, env))
		return (-1);
	line = init_lst(argv, argc, 2);
	if (!line)
		return (-1);
	if (!pipex_launcher(line, env))
		return (-1);
	free_cmd_lst(line);
	return (0);
}
