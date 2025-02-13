/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:06:58 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/12 16:21:38 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

static char	**extract_absolute_path(char *path_to_try, char *cmd_to_try)
{
	char	*valid;
	char	*full_cmd;
	char	**extracted;

	valid = ft_strjoin(path_to_try, "/");
	if (!valid || !valid[0])
		return (NULL);
	full_cmd = ft_strjoin(valid, cmd_to_try);
	free(valid);
	if (!full_cmd || !full_cmd[0])
		return (NULL);
	extracted = ft_split(full_cmd, " ");
	free(full_cmd);
	if (!extracted || !extracted[0])
	{
		free_array(extracted);
		return (NULL);
	}
	return (extracted);
}

//check absolute path and relative path
static int	is_a_valid_path(char **cmds, char **path, int i)
{
	char	**tokens;
	int		j;
	int		found;

	tokens = NULL;
	while (cmds[i])
	{
		j = 0;
		found = 0;
		while (path[j])
		{
			tokens = extract_absolute_path(path[j], cmds[i]);
			if (tokens && tokens[0] && access(tokens[0], F_OK) == 0
				&& access(tokens[0], X_OK) == 0)
			{
				found = 1;
				break;
			}
			free_array(tokens);
			j++;
		}
		if (!found)
		{
			if (tokens)
				free_array(tokens);
			return (0);
		}
		free_array(tokens);
		i++;
	}
	return (1);
}

static char	**find_path(char **env, char *path, int len_of_path)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(path, env[i], len_of_path))
			return (ft_split(env[i] + len_of_path, ":"));
		i++;
	}
	return (NULL);
}

//check whitespaces, NULL value and if its an executable command
int	command_checker(char **av, char **env, int ac)
{
	char	**path;
	char	**cmds;
	int		i;

	i = 2;
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
	{
		free_array(path);
		return (0);
	}
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
	if (!file_checker(av[1], av[4]))
		return (0);
	if (!command_checker(av, env, ac))
		return (0);
	return (1);
}
