/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:50:50 by mjzlak            #+#    #+#             */
/*   Updated: 2024/11/24 19:59:25 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbelem, size_t size)
{
	void	*res;
	size_t	total;

	if (nbelem == 0 || size == 0)
		return (malloc(0));
	total = nbelem * size;
	if (size != 0 && total / size != nbelem)
		return (NULL);
	res = malloc(total);
	if (!res)
		return (NULL);
	ft_bzero(res, total);
	return (res);
}
