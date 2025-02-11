/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:29:18 by mjzlak            #+#    #+#             */
/*   Updated: 2025/02/11 13:15:20 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static size_t	get_words_count(const char *str, char *charset)
{
	size_t	count;
	size_t	i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(charset, str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_sep(charset, str[i]))
			i++;
	}
	return (count);
}

static size_t	get_size(const char *str, char *charset)
{
	size_t	i;

	i = 0;
	while (str[i] && !is_sep(charset, str[i]))
		i++;
	return (i);
}

char	**ft_split(const char *str, char *charset)
{
	char	**array;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	array = malloc(sizeof(char *) * (get_words_count(str, charset) + 1));
	if (!array)
		return (NULL);
	while (i < get_words_count(str, charset))
	{
		while (str[j] && is_sep(charset, str[j]))
			j++;
		if (str[j])
			array[i] = ft_substr(str, j, get_size(&str[j], charset));
		if (!array[i])
			return (free_array(array), NULL);
		while (str[j] && !is_sep(charset, str[j]))
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
