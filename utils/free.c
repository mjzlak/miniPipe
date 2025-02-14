/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:22:18 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/13 17:43:53 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	free_array_and_return_zero(char **array)
{
	free_array(array);
	return (0);
}

void	free_cmd_lst(t_cmd *lst)
{
	t_cmd	*temp;
	int		i;

	while (lst)
	{
		if (lst->cmd)
		{
			i = 0;
			while (lst->cmd[i])
				free(lst->cmd[i++]);
			free(lst->cmd);
		}
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

t_cmd	*free_lst_and_return_null(t_cmd *lst)
{
	free_cmd_lst(lst);
	return (NULL);
}
