/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:06:58 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/11 08:06:59 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

//check absolute path and relative path
static int	is_a_valid_path(char *cmd1, char *cmd2, char **path)
{
	char	*valid;
	char	**splitted;
	int		i;
	int		bool;

	i = 0;
	bool = 0;
	while (path[i])
	{
		valid = ft_strjoin(path[i], "/");
		valid = ft_strjoin(valid, cmd1);
		splitted = ft_split(valid, " ");
		if (access(splitted[0], F_OK) == 0 && access(splitted[0], X_OK) == 0)
			bool += 1;
		valid = ft_strjoin(path[i], "/");
		valid = ft_strjoin(valid, cmd2);
		splitted = ft_split(valid, " ");
		if (access(splitted[0], F_OK) == 0 && access(splitted[0], X_OK) == 0)
			bool += 1;
		if (bool > 1)
			return (1);
		i++;
	}
	return (0);
}

//check whitespaces, NULL value and if its an executable command
int	command_checker(char *cmd1, char *cmd2, char **env)
{
	char	**path;

	if (!*cmd1 || !*cmd2)
		return (0);
	if (cmd1[0] == ' ' || cmd2[0] == ' ')
		return (0);
	if (cmd1[0] >= 9 && cmd1[0] <= 13)
		return (0);
	if (cmd2[0] >= 9 && cmd2[0] <= 13)
		return (0);
	path = find_path(env, "PATH=", 5);
	if (!is_a_valid_path(cmd1, cmd2, path))
		return (0);
	return (1);
}

//check existing files and permissions
int	file_checker(char *file1, char *file2)
{
	int	fd;

	(void)file1;
	if (access(file1, F_OK) < 0 || access(file1, R_OK) < 0)
		return (0);
	if ((access(file2, F_OK) == 0) && (access(file2, W_OK) < 0))
		return (0);
	if (access(file2, F_OK) < 0)
	{
		fd = open(file2, O_CREAT);
		close(fd);
		return (1);
	}
	return (1);
}

int	error_handling(int ac, char **av, char **env)
{
	if (ac != 5)
		return (0);
	if (!file_checker(av[1], av[4]))
		return (0);
	if (!command_checker(av[2], av[3], env))
		return (0);
	return (1);
}
