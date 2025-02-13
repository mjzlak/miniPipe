/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:15:35 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/24 11:14:04 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char			**cmd;
	char			*infile;
	char			*outfile;
	struct s_cmd	*next;
} t_cmd;

// error_handling.c
int			file_checker(char *file1, char *file2);
int			command_checker(char **av, char **env, int ac);
int			error_handling(int ac, char **av, char **env);

// utils/free.c
void	free_array(char **array);
void	free_cmd_lst(struct s_cmd *lst);
t_cmd	*free_lst_and_return_null(t_cmd *lst);
//utils/init_lst.c
t_cmd	*init_lst(char **argv, int argc, int i);

// main.c
int		main(int argc, char **argv, char **env);

#endif
