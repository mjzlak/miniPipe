/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:58:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/13 16:25:45 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	*line;

	if (!error_handling(argc, argv, env))
		return (-1);
	line = init_lst(argv, argc, 2);
	if (!line)
		return (-1);
/*	if (!pipex_launcher(line, env))
		return (-1);*/
	free_cmd_lst(line);
	return (0);
}
