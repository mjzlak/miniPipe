/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:44:48 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/19 18:37:33 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_all_opened_files(int *files, int *pipe_files, char *error)
{
	int	i;

	if (error)
		perror(error);
	if (files)
	{
		i = 0;
		while (i < 3 && files[i] != -1)
		{
			close(files[i]);
			files[i] = -1;
			i++;
		}
	}
	if (pipe_files)
	{
		i = 0;
		while (i < 3 && pipe_files[i] != -1)
		{
			close(pipe_files[i]);
			pipe_files[i] = -1;
			i++;
		}
	}
}
