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
# include <sys/wait.h>

typedef struct s_cmd
{
	char			**cmd;
	char			*infile;
	char			*outfile;
	struct s_cmd	*next;
} t_cmd;

// error_handling.c
int			file_checker(char *file1, char *file2);
int			command_checker(char **av, char **env, int ac, int i);
int			error_handling(int ac, char **av, char **env);

// utils/free.c
void	free_array(char **array);
int		free_array_and_return_zero(char **array);
void	free_cmd_lst(t_cmd *lst);
t_cmd	*free_lst_and_return_null(t_cmd *lst);
//	utils/init_lst.c
t_cmd	*init_lst(char **argv, int argc, int i);
// utils/path_checker.c
int		is_a_valid_path(char **cmds, char **path, int i);
char	**find_path(char **env, char *path, int len_of_path);
char	*get_absolute_path(char *cmd, char **env);

// main.c
int		main(int argc, char **argv, char **env);

#endif
