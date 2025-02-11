/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:33 by mloeffer          #+#    #+#             */
/*   Updated: 2024/11/15 18:29:50 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	memmoving(unsigned char *d, unsigned char *s, size_t n, size_t i)
{
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buf_dest;
	unsigned char	*buf_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	buf_dest = (unsigned char *)dest;
	buf_src = (unsigned char *)src;
	i = 0;
	memmoving(buf_dest, buf_src, n, i);
	return (buf_dest);
}
