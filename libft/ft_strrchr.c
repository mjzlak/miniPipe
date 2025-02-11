/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:57:30 by mjzlak            #+#    #+#             */
/*   Updated: 2024/11/22 13:51:14 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	len;
	char	ch;
	char	*str;

	len = ft_strlen(s);
	str = (char *)s;
	ch = (char)c;
	if (ch == '\0')
		return (&str[len]);
	while (len >= 0)
	{
		if (str[len] == ch)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
