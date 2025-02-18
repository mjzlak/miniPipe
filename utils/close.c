/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:44:48 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/18 17:15:28 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    close_all_opened_files(int *files, int *pipe_files, char *error)
{
    int i;

    i = 0;
    if (!files && !pipe_files)
        return ;
    if (error)
        perror(error);
    while (files[i])
    {
        if (files[i] != -1)
            close(files[i]);
        i++;
    }
    i = 0;
    while(pipe_files[i])
    {
        if (pipe_files[i] != -1)
            close(pipe_files[i]);
        i++;
    }
}
