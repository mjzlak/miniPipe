/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjzlak <mjzlak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:49:57 by mjzlak            #+#    #+#             */
/*   Updated: 2024/11/15 09:53:17 by mjzlak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_start(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	get_end(const char *s1, const char *set, size_t start)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*buf;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set, start);
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	buf = res;
	while (start < end)
	{
		*buf = s1[start];
		buf++;
		start++;
	}
	*buf = '\0';
	return (res);
}
