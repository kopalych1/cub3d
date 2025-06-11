/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:49:09 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/10 13:57:08 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	set_error(t_cub_data *cub_data, int error)
{
	cub_data->error = error;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned long	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i] != 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

int	ft_arr_len(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	*line_to_int_arr(char *line, int width)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * width);
	if (!ret)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == 9)
			ret[i] = -1;
		else if (line[i] == '0')
			ret[i] = 0;
		else if (line[i] == '1')
			ret[i] = 1;
		else if (line[i] == '2')
			ret[i] = 2;
		else
			return (NULL);
		i++;
	}
	while (i < width)
		ret[i++] = -1;
	return (ret);
}

void	init_data(t_cub_data *c, t_node *map_head, t_node *list_head)
{
	c->error = 0;
	c->so_texture = NULL;
	c->no_texture = NULL;
	c->we_texture = NULL;
	c->ea_texture = NULL;
	c->ceiling_rgb[0] = 0;
	c->ceiling_rgb[1] = 0;
	c->ceiling_rgb[2] = 0;
	c->floor_rgb[0] = 0;
	c->floor_rgb[1] = 0;
	c->floor_rgb[2] = 0;
	map_head->prev = NULL;
	map_head->next = NULL;
	map_head->line = NULL;
	list_head->prev = NULL;
	list_head->next = NULL;
	list_head->line = NULL;
	c->map_i = NULL;
	c->map_c = NULL;
}
