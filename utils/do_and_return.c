/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_and_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:07:57 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/18 19:02:58 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	free_array_and_return_zero(char **array, int return_value)
{
	free_array(array);
	return (return_value);
}
t_cmd	*free_lst_and_return_null(t_cmd *lst)
{
	free_cmd_lst(lst);
	return (NULL);
}

int close_and_return(int *files, int *pipe_files, int return_value, char *error)
{
    close_all_opened_files(files, pipe_files, error);
    return (return_value);
}

int    perror_and_return(char *error, int return_value)
{
    perror(error);
    return (return_value);
}