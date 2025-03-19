/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:49:09 by vcaratti          #+#    #+#             */
/*   Updated: 2025/03/19 14:04:53 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	process_map(char *line, t_cub_data *cub_data)
int	process_texture(char *line, t_cub_data *cub_data)
int	process_rgb(char *line, t_cub_data *cub_data)
int	process_error(char *line, t_cub_data *cub_data)

void	init_structs(t_cub_data *c, t_processing *p)
{
	c->map_closed = 0;
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
	p->processes[1] = &process_rgb;
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		||c == '\v' || c == '\f' || c == '\r');
}

int	is_map_data(char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (ft_isspace((int)*line) ||
	}
}

int	validate_map(char *line)
{
	if (
}

int	validate(char *line)
{
	int	validated;

	validated = validate_map(char *line);
}

int	process_identify(char *line)
{
	int	is_valid;

	is_valid = validate(char *line);
}

int	main(int argc, char **argv)//later get_cub_data(...)
{
	t_cub_data	cub_data;
	t_processing	processing;

	init_structs(&cub_data, &processing);
}
