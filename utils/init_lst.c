/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:54:02 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/13 18:32:13 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*static t_cmd	*init_first_node(char **argv)
{
	t_cmd *head;

	head = malloc(sizeof(t_cmd));
	if (!head)
		return (NULL);
	head->infile = argv[1];
	head->outfile = NULL;
	head->cmd = NULL;
	head->next = NULL;
	return (head);
}

static t_cmd	*init_last_node(char **argv, int argc)
{
	t_cmd *out_node;

	out_node = malloc(sizeof(t_cmd));
	if (!out_node)
		return (NULL);
	out_node->infile = NULL;
	out_node->outfile = argv[argc - 1];
	__builtin_printf("outfile = %s\n", argv[argc - 1]);
	out_node->cmd = NULL;
	out_node->next = NULL;
	return (out_node);
}*/

t_cmd	*add_cmd_to_lst(char **argv, int index)
{
	t_cmd *new_node;

	new_node = malloc(sizeof(t_cmd));
	if (!new_node)
		return (NULL);
	new_node->cmd = ft_split(argv[index], " ");
	new_node->infile = NULL;
	new_node->outfile = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_cmd	*init_lst(char **argv, int argc, int i)
{
	t_cmd	*head;
	t_cmd	*current;

	head = add_cmd_to_lst(argv, i);
	if (!head)
		return (NULL);
	head->infile = argv[1];
	current = head;
	i++;
	while (i < argc - 1)
	{
		current->next = add_cmd_to_lst(argv, i);
		if (!current->next)
			return (free_lst_and_return_null(head));
		current = current->next;
		i++;
	}
	current->outfile = argv[argc - 1];
	return (head);
}
