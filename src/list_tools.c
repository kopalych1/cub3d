/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:30:39 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/11 12:13:15 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	path_to_list(t_cub_data *cub_data, char *path, t_node *list_head)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (set_error(cub_data, 4), 1);
	line = get_next_line(fd);
	if (!line)
		return (set_error(cub_data, 4), 1);
	while (line)
	{
		list_head->next = malloc(sizeof(t_node));
		if (!list_head->next)
			return (set_error(cub_data, 1), free(line), 1);
		list_head->next->line = line;
		list_head->next->prev = list_head;
		list_head->next->next = NULL;
		list_head = list_head->next;
		line = get_next_line(fd);
	}
	return (0);
}

t_node	*list_pop(t_node **to_pop_p)
{
	t_node	*to_pop;
	t_node	*next;

	to_pop = *to_pop_p;
	next = to_pop->next;
	if (to_pop->prev)
		to_pop->prev->next = to_pop->next;
	if (to_pop->next)
		to_pop->next->prev = to_pop->prev;
	to_pop->prev = NULL;
	to_pop->next = NULL;
	*to_pop_p = next;
	return (to_pop);
}

void	list_add(t_node *list, t_node *to_add)
{
	while (list->next)
		list = list->next;
	list->next = to_add;
	to_add->prev = list;
}

void	free_node(t_node *node)
{
	free(node->line);
	if (node->prev)
		node->prev->next = 0;
	if (node->next)
		node->next->prev = 0;
	free(node);
}

void	free_list(t_node *list_head)
{
	t_node	*current;
	t_node	*next;

	if (!list_head)
		return ;
	if (!list_head->next)
		return ;
	current = list_head->next;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
}
