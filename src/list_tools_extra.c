/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:30:39 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/10 13:56:40 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	list_len(t_node *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	max_list_width(t_node *list)
{
	size_t	max;

	max = 0;
	while (list)
	{
		if (ft_strlen(list->line) > max)
			max = ft_strlen(list->line);
		list = list->next;
	}
	return ((int)max);
}

void	remove_next_lines(t_node *list)
{
	char	*line;

	while (list)
	{
		line = list->line;
		while (*line)
		{
			if (*line == '\n')
				*line = '\0';
			line++;
		}
		list = list->next;
	}
}
