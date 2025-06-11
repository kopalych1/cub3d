/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:34:20 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/10 13:56:48 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	is_map_data(char *line)
{
	if (!line || is_whiteline(line))
		return (0);
	while (*line)
	{
		if (!(ft_isspace((int)*line) || ft_isnum((int)*line)
				|| is_orientation((int)*line)))
			return (0);
		line++;
	}
	return (1);
}

void	map_trim(t_node *map_head)
{
	t_node	*map;
	t_node	*tmp;

	map = map_head->next;
	while (is_whiteline(map->line))
		free_node(list_pop(&map));
	while (map->next)
		map = map->next;
	while (is_whiteline(map->line))
	{
		tmp = map->prev;
		free_node(list_pop(&map));
		map = tmp;
	}
	tmp = map_head->next;
}

int	insert_spaces(char **line, int *i)
{
	char	*newline;
	int		j;

	newline = malloc(sizeof(char) * (ft_strlen(*line) + 8 + 1));
	if (!newline)
		return (1);
	j = -1;
	while (++j < *i)
		newline[j] = (*line)[j];
	j = 0;
	while (j < 8)
		newline[*i + j++] = ' ';
	while ((*line)[*i + j - 8])
	{
		newline[*i + j] = (*line)[*i + j - 7];
		j++;
	}
	newline[*i + j] = '\0';
	free(*line);
	*line = newline;
	return (0);
}

int	replace_tabs_with_spaces(t_node *map_head)
{
	t_node	*current;
	int		i;

	current = map_head->next;
	while (current)
	{
		i = 0;
		while (current->line[i])
		{
			if (current->line[i] == '\t')
			{
				if (insert_spaces(&(current->line), &i))
					return (1);
			}
			i++;
		}
		current = current->next;
	}
	return (0);
}

int	extract_map(t_cub_data *cub_data, t_node *list, t_node *map_head)
{
	while (list)
	{
		if (is_map_data(list->line))
			list_add(map_head, list_pop(&list));
		else if (map_head->next == NULL)
			list = list->next;
		else
			break ;
	}
	if (!map_head->next)
		return (set_error(cub_data, 5), 1);
	if (replace_tabs_with_spaces(map_head))
		return (set_error(cub_data, 1), 1);
	map_trim(map_head);
	list = map_head->next;
	while (list)
	{
		if (is_whiteline(list->line))
			return (set_error(cub_data, 2), 1);
		list = list->next;
	}
	return (0);
}
