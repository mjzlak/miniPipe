/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:42 by mloeffer          #+#    #+#             */
/*   Updated: 2024/11/21 17:57:50 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buf;
	size_t			i;

	if (n == 0)
		return (s);
	buf = (unsigned char *)s;
	i = 0;
	while (i < n)
		buf[i++] = (unsigned char)c;
	return (s);
}
