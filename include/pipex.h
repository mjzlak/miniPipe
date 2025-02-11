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

// error_handling.c
int		file_checker(char *file1, char *file2);
int		command_checker(char *cmd1, char *cmd2, char **env);
int		error_handling(int ac, char **av, char **env);
// utils.c
int		is_same_strn(char *str1, char *str2, int size);
char	**find_path(char **env, char *path, int len_of_path);
char	*ft_strcat(char *base, char *to_cat, char *add);

// main.c
int		main(int argc, char **argv, char **env);

#endif
