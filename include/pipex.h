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

// Structure for linked list
// cmd		- Commands received from arguments
// infile	- Input file
// outfile	- Output file
// next		- Next node in linked list
typedef struct s_cmd
{
	char			**cmd;
	char			*infile;
	char			*outfile;
	struct s_cmd	*next;
} t_cmd;

// MAIN.C
// @param	argc		Number of arguments
// @param	argv		Arguments
// @param	env			Environment variables
// @return				0 if success, 1 if error
int		main(int argc, char **argv, char **env);

// ERROR_HANDLING.C
// @param	file1		Input file
// @param	file2		Output file
// @return				0 if error, 1 if success
int			file_checker(char *file1, char *file2);
// @param	av			Arguments
// @param	env			Environment variables
// @param	ac			Number of arguments
// @param	i			Index
// @return				0 if error, 1 if success
int			command_checker(char **av, char **env, int ac, int i);
// @param	ac			Number of arguments
// @param	av			Arguments
// @param	env			Environment variables
// @return				0 if error, 1 if success
int			error_handling(int ac, char **av, char **env);

//	UTILS/INIT_LST.C
// @param	argv		Arguments
// @param	argc		Number of arguments
// @param	i			Index
// @return				Linked list or NULL
t_cmd	*init_lst(char **argv, int argc, int i);
// utils/path_checker.c
// @param	cmds		Commands
// @param	path		Path to check
// @param	i			Index
// @return				1 if valid, 0 if invalid
int		is_a_valid_path(char **cmds, char **path, int i);
// @param	env			Environment variables
// @param	path		Path to find
// @param	len_of_path	Length of path
// @return				Path or NULL
char	**find_path(char **env, char *path, int len_of_path);
// @param	cmd			Command to find path
// @param	env			Environment variables
// @return				Absolute path or NULL
char	*get_absolute_path(char *cmd, char **env);
// UTILS/FREE.C
// @param	array		Array to free
void	free_array(char **array);
// @param	lst			Linked list to free
void	free_cmd_lst(t_cmd *lst);
// UTILS/CLOSE.C
// @param	files		Files to close
// @param	pipe_files	Pipe files to close
// @param	error		Error message
void	close_all_opened_files(int *files, int *pipe_files, char *error);
// UTILS/DO_AND_RETURN.C
// @param	array		Array to free
// @param	return_value	Return value after freeing
int		free_array_and_return_zero(char **array, int return_value);
// @param	lst			Linked list to free
// @return				NULL
t_cmd	*free_lst_and_return_null(t_cmd *lst);
// @param	files		Files to close
// @param	pipe_files	Pipe files to close
// @param	return_value	Return value
// @param	error		Error message to print
// @return				Return value after closing files
int		close_and_return(int *files, int *pipe_files, int return_value, char *error);
// @param	error		Error message to print
// @param	return_value	Return value after printing error
int		perror_and_return(char *error, int return_value);

#endif
