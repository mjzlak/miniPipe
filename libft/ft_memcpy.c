/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjzlak <mjzlak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:08 by mloeffer          #+#    #+#             */
/*   Updated: 2024/11/15 09:50:55 by mjzlak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buf_dest;
	unsigned char	*buf_src;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	i = 0;
	buf_dest = (unsigned char *)dest;
	buf_src = (unsigned char *)src;
	while (i < n)
	{
		buf_dest[i] = buf_src[i];
		i++;
	}
	return (buf_dest);
}
