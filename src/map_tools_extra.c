/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:49:09 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/10 13:56:54 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	extract_p_orientation(t_cub_data *cub_data)
{
	t_node	*i;
	char	*j;
	int		found;

	found = 0;
	i = cub_data->map_head.next;
	while (i)
	{
		j = i->line;
		while (*j)
		{
			if (*j == 'S' || *j == 'N' || *j == 'E' || *j == 'W')
			{
				cub_data->player.direction = *j;
				*j = '2';
				found++;
			}
			j++;
		}
		i = i->next;
	}
	if (found)
		return (0);
	return (1);
}

int	extract_p_position(t_cub_data *cub_data)
{
	int	found;
	int	x;
	int	y;

	found = 0;
	y = -1;
	while (++y < cub_data->height)
	{
		x = -1;
		while (++x < cub_data->width)
		{
			if (cub_data->map_i[y][x] == 2)
			{
				found++;
				cub_data->map_i[y][x] = 0;
				cub_data->player.x = x;
				cub_data->player.y = y;
			}
		}
	}
	if (found != 1)
		return (1);
	return (0);
}

int	convert_map(t_cub_data *cub_data)
{
	t_node	*current;
	int		i;

	if (extract_p_orientation(cub_data))
		return (set_error(cub_data, 3), 1);
	cub_data->width = max_list_width(cub_data->map_head.next);
	cub_data->height = list_len(cub_data->map_head.next);
	cub_data->map_i = malloc(sizeof(int *) * (cub_data->height + 1));
	if (!cub_data->map_i)
		return (set_error(cub_data, 1), 1);
	cub_data->map_i[cub_data->height] = NULL;
	current = cub_data->map_head.next;
	i = 0;
	while (current)
	{
		cub_data->map_i[i] = line_to_int_arr(current->line, cub_data->width);
		if (!cub_data->map_i[i++])
			return (set_error(cub_data, 1), 1);
		current = current->next;
	}
	return (0);
}

int	check_around(int x, int y, t_cub_data *cub_data)
{
	int	**map_i;

	map_i = cub_data->map_i;
	if (x == 0 || y == 0 || x == cub_data->width - 1
		|| y == cub_data->height - 1)
	{
		if (map_i[y][x] != 1 && map_i[y][x] != -1)
			return (1);
	}
	else if (map_i[y][x] == 0 || map_i[y][x] == 2)
	{
		if (!is_wall_or_air(map_i[y - 1][x])
				|| !is_wall_or_air(map_i[y + 1][x])
			|| !is_wall_or_air(map_i[y][x - 1])
		|| !is_wall_or_air(map_i[y][x + 1]))
			return (1);
	}
	return (0);
}

int	verify_map(t_cub_data *cub_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub_data->height)
	{
		x = 0;
		while (x < cub_data->width)
		{
			if (check_around(x, y, cub_data))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
