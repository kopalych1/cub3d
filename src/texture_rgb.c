/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:48:42 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/12 13:52:08 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	process_identify(char *line)
{
	if (!line)
		return (3);
	if (ft_strnstr(line, "NO", ft_strlen(line))
		|| ft_strnstr(line, "SO", ft_strlen(line))
		|| ft_strnstr(line, "WE", ft_strlen(line))
		|| ft_strnstr(line, "EA", ft_strlen(line)))
		return (1);
	if (ft_strnstr(line, "F ", ft_strlen(line))
		|| ft_strnstr(line, "C ", ft_strlen(line)))
		return (2);
	if (is_whiteline(line))
		return (0);
	return (3);
}

void	set_texture(t_cub_data *cub_data, char **to_set, char *new_texture)
{
	if (*to_set)
	{
		free(*to_set);
		set_error(cub_data, 4);
	}
	*to_set = new_texture;
}

int	process_texture(char *line, t_cub_data *cub_data)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (set_error(cub_data, 1), 1);
	if (ft_arr_len(line_split) != 2)
		return (set_error(cub_data, 4), free_char_arr(line_split), 1);
	if (!ft_strcmp(line_split[0], "SO"))
		set_texture(cub_data, &cub_data->tex_paths[SOUTH], line_split[1]);
	else if (!ft_strcmp(line_split[0], "NO"))
		set_texture(cub_data, &cub_data->tex_paths[NORTH], line_split[1]);
	else if (!ft_strcmp(line_split[0], "WE"))
		set_texture(cub_data, &cub_data->tex_paths[WEST], line_split[1]);
	else if (!ft_strcmp(line_split[0], "EA"))
		set_texture(cub_data, &cub_data->tex_paths[EAST], line_split[1]);
	free(line_split[0]);
	free(line_split);
	return (cub_data->error);
}

int	colors_to_int(t_cub_data *cub_data, char **colors, int *colors_int)
{
	int	i;
	int	not_rgb;

	i = 0;
	not_rgb = 0;
	while (colors[i])
	{
		colors_int[i] = ft_atoi(colors[i]);
		if (colors_int[i] < 0 || colors_int[i] > 255)
			not_rgb = 1;
		i++;
	}
	if (not_rgb)
		set_error(cub_data, 4);
	return (not_rgb);
}

int	process_rgb(char *line, t_cub_data *cub_data)
{
	char	**line_split;
	char	**color_split;
	int		*colors;
	int		not_rgb;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (set_error(cub_data, 1), 1);
	if (ft_arr_len(line_split) != 2)
		return (set_error(cub_data, 4), free_char_arr(line_split), 1);
	color_split = ft_split(line_split[1], ',');
	if (!color_split)
		return (set_error(cub_data, 1), free_char_arr(line_split), 1);
	if (ft_arr_len(color_split) != 3)
		return (set_error(cub_data, 4), free_char_arr(line_split)
			, free_char_arr(color_split), 1);
	if (!ft_strcmp(line_split[0], "C"))
		colors = cub_data->ceiling_rgb;
	else
		colors = cub_data->floor_rgb;
	not_rgb = colors_to_int(cub_data, color_split, colors);
	free_char_arr(line_split);
	free_char_arr(color_split);
	return (not_rgb);
}
