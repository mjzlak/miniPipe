/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:45:47 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/13 16:16:38 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
static int check_path(char **cmds, char **path, int i)
{
    char **tokens;
    int j;
    int found;

    j = 0;
    found = 0;
    while (path[j])
    {
        tokens = extract_absolute_path(path[j], cmds[i]);
        if (tokens && tokens[0] && access(tokens[0], F_OK) == 0
            && access(tokens[0], X_OK) == 0)
        {
            found = 1;
            free_array(tokens);
            return (1);
        }
        free_array(tokens);
        j++;
    }
    return (0);
}

int is_a_valid_path(char **cmds, char **path, int i)
{
    while (cmds[i])
    {
        if (!check_path(cmds, path, i))
            return (0);
        i++;
    }
    return (1);
}
