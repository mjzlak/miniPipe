/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:54:02 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/13 13:54:06 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static t_cmd	*init_first_node(char **argv)
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
	out_node->cmd = NULL;
	out_node->next = NULL;
	return (out_node);
}

static t_cmd	*add_cmd_to_lst(char **argv, t_cmd *head, int i)
{
	t_cmd *new_node = malloc(sizeof(t_cmd));
	if (!new_node)
	{
		free_cmd_lst(head);
		return (NULL);
	}
	new_node->cmd = ft_split(argv[i], " ");
	new_node->infile = NULL;
	new_node->outfile = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_cmd	*init_lst(char **argv, int argc, int i)
{
	t_cmd	*head;
	t_cmd	*current;
	t_cmd	*last_node;

	head = init_first_node(argv);
	if (!head)
		return (NULL);
	current = head;
	while (i < argc - 2)
	{
		current->next = add_cmd_to_lst(argv, head, i);
		if (!current->next)
			return (free_lst_and_return_null(head));
		current = current->next;
		i++;
	}
	last_node = init_last_node(argv, argc);
	if (!last_node)
		return (free_lst_and_return_null(head));
	current->next = last_node;
	return (head);
}
