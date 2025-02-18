/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:06:58 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/18 18:51:19 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

//check whitespaces, NULL value and if its an executable command
int	command_checker(char **av, char **env, int ac, int i)
{
	char	**path;
	char	**cmds;

	while(i++ < ac - 1)
		if (!av[i] || av[i][0] == ' ' || (av[i][0] >= 9 && av[i][0] <= 13))
			return (0);
	cmds = malloc(sizeof(char *) * (ac - 3 + 1));
	if (!cmds)
		return (0);
	i = 0;
	while (i < ac - 3)
	{
		cmds[i] = av[i + 2];
		i++;
	}
	cmds[i] = NULL;
	path = find_path(env, "PATH=", 5);
	if (!path)
		return (0);
	if (!is_a_valid_path(cmds, path, 0))
		return (free_array_and_return_zero(path, 0));
	free(cmds);
	free_array(path);
	return (1);
}

//check existing files and permissions
int	file_checker(char *file1, char *file2)
{
	int	fd;

	if (access(file1, F_OK) < 0 || access(file1, R_OK) < 0)
		return (0);
	if ((access(file2, F_OK) == 0) && (access(file2, W_OK) < 0))
		return (0);
	if (access(file2, F_OK) < 0)
	{
		fd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			return (0);
		close(fd);
		return (1);
	}
	return (1);
}

int	error_handling(int ac, char **av, char **env)
{
	if (ac < 5)
		return (0);
	if (!file_checker(av[1], av[ac - 1]))
		return (0);
	if (!command_checker(av, env, ac, 2))
		return (0);
	return (1);
}
