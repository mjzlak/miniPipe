/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:12:16 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/11 11:12:17 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	is_same_strn(char *str1, char *str2, int size)
{
	int	i;

	i = 0;
	while (i < size && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

char	**find_path(char **env, char *path, int len_of_path)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (is_same_strn(path, env[i], len_of_path))
			return (ft_split(env[i] + len_of_path, ":"));
		i++;
	}
	return (NULL);
}

char	*ft_strcat(char *base, char *to_cat, char *add)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (base[i])
		i++;
	if (add)
		while (add[z])
			base[i++] = add[z++];
	if (!*to_cat)
		return (base);
	while (to_cat[j])
		base[i++] = to_cat[j++];
	return (base);
}
