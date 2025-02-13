/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:58:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/11 07:58:34 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	/*char	*cmd1;
	char	*cmd2;
	int		file1;
	int		file2;*/
	t_cmd	*line;

	if (!error_handling(argc, argv, env))
		return (-1);
	line = init_lst(argv, argc, 2);
	/*cmd1 = argv[2];
	cmd2 = argv[3];
	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_WRONLY);
	close(file1);
	close(file2);*/
	free_cmd_lst(line);
	return (0);
}
