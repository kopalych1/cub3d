/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:49:09 by vcaratti          #+#    #+#             */
/*   Updated: 2025/04/02 12:56:00 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	process_map(char *line, t_cub_data *cub_data)
{
	if (cub_data->map_status != 0)
		return (1);
}

int	process_texture(char *line, t_cub_data *cub_data)
{
	char	**line_split;
	int	fd;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (free(line), 1);
	free(line);
	if (ft_arr_len(line_split) != 2)
		return (free(line_split[0]), free(line_split[1]), 1);
	fd = open(0777, line_split[1]);
	if (fd == -1)
		return (free(line_split[0]), free(line_split[1]), 1);
	close( fd );
	if (!ft_strcmp(line_split[0], "SO"))
		cub_data->SO_TEXTURE = line_split[1];
	else if (!ft_strcmp(line_split[0], "NO"))
		cub_data->NO_TEXTURE = line_split[1];
	else if (!ft_strcmp(line_split[0], "WE"))
		cub_data->WE_TEXTURE = line_split[1];
	else if (!ft_strcmp(line_split[0], "EA"))
		cub_data->EA_TEXTURE = line_split[1];
	free(line_split[0]);
	return (0);
}

int	process_rgb(char *line, t_cub_data *cub_data)
{
	char	**line_split;
	char	**color_split;
	int	*colors;
	int	not_rgb;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (free(line), 1);
	free(line);
	if (ft_arr_len(line_split) != 2)
		return (free(line_split[0]), free(line_split[1]), 1);
	color_split = ft_split(line_split[1], ',');
	if (!color_split)
		return (free(line_split[0], free(line_split[1]), 1);
	if (ft_arr_len(color_split) != 3)
		return (free(line_split[0], free(line_split[1]), free(color_split[1...2]), 1);
	if (!ft_strcmp(line_split[0], "C"))
		colors = cub_data->ceiling_rgb;
	else
		colors = cub_data->floor_rgb;
	not_rgb = 0;
	while (*color_split)
	{
		*colors = ft_atoi(*color_split);
		free(*color_split);
		if (*colors < 0 || *colors > 255)
			not_rgb = 1;
		colors++;
		color_split++;
	}
	free(line_split);
	free(color_split);
	return (not_rgb);
}

int	process_error(char *line, t_cub_data *cub_data)

void	init_structs(t_cub_data *c, t_processing *p)
{
	c->map_status = 0;
	c->map_start = NULL;
	c->SO_TEXTURE = NULL;
	c->NO_TEXTURE = NULL;
	c->WE_TEXTURE = NULL;
	c->EA_TEXTURE = NULL;
	c->ceiling_rgb[0] = 0;
	c->ceiling_rgb[1] = 0;
	c->ceiling_rgb[2] = 0;
	c->floor_rgb[0] = 0;
	c->floor_rgb[1] = 0;
	c->floor_rgb[2] = 0;
	p->fd = -1;
	p->processes[0] = &process_map;
	p->processes[1] = &process_texture;
	p->processes[2] = &process_rgb;
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		||c == '\v' || c == '\f' || c == '\r');
}

int	ft_isnum(int c)
{
	return (c >= 48 && c <= 57);
}

int	is_orientation(int c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	is_map_data(char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (!(ft_isspace((int)*line) || ft_isnum((int)*line) || is_orientation((int)*line))
			return (0);
		line++;
	}
	return (1);
}

int	validate_map(char *line)
{
	if (!line)
		return ();
}

int	validate(char *line)
{
	int	validated;

	validated = validate_map(char *line);
}

int	process_identify(char *line)
{
	//int	is_valid;
	if (!line)
		return (3); 
	if (is_map_data(line))
		return (0);
	if (ft_strnstr(line, "NO", strlen(line)) || ft_strnstr(line, "SO", strlen(line))
		|| ft_strnstr(line, "WE", strlen(line)) || ft_strnstr(line, "EA", strlen(line)))
		return (1);
	if (ft_strnstr(line, "F ", strlen(line)) || ft_strnstr(line, "C ", strlen(line)))
		return (2);
	return (3);
	//is_valid = validate(char *line);
}

int	main(int argc, char **argv)//later get_cub_data(...)
{
	t_cub_data	cub_data;
	t_processing	processing;

	init_structs(&cub_data, &processing);
}
