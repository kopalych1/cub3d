/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 06:04:02 by akostian          #+#    #+#             */
/*   Updated: 2025/05/02 06:14:30 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief Calculates the wall position offset for texture mapping.
 * 
 * @param p   The point on the wall.
 * @param dir The direction of the wall (NORTH, SOUTH, EAST, or WEST).
 * 
 * @return The fractional offset of the point along the wall.
 */
static double	wall_pos(t_point p, enum e_direction dir)
{
	if (dir == NORTH || dir == SOUTH)
		return (ceil(p.x) - p.x);
	return (ceil(p.y) - p.y);
}

static void	put_wall_segment(
	t_game *game, t_draw_math *m, int i
)
{
	int	j;

	m->distance = dist(game->player.pos, m->inter)
		* cos(M_PI / 180 * (m->ray_angle - game->player.angle));
	m->wall_height = round(WALL_HEIGHT / m->distance);
	j = -1;
	while (++j < m->wall_height)
	{
		m->screen_x = SCREEN_WIDTH - i;
		m->screen_y = (SCREEN_HEIGHT - m->wall_height) / 2 + j;
		if ((m->screen_y <= 0)
			|| (m->screen_y > SCREEN_HEIGHT))
			continue ;
		m->dir = wall_direction(m->inter, m->ray_angle);
		m->tex_x = wall_pos(m->inter, m->dir) * game->tex[m->dir].width;
		m->tex_y = floor((double)j / (double)m->wall_height
				* (double)game->tex[m->dir].height);
		draw_pixel(game->screen,
			m->screen_x, m->screen_y,
			get_pixel_color(game->tex[m->dir].p, m->tex_x, m->tex_y));
	}
}

void	render(t_game *game)
{
	const double	start_angle = (game->player.angle - (FOV / 2) + 360);
	const double	angle_step = (double)FOV / (double)SCREEN_WIDTH;
	t_draw_math		m;
	int				i;

	draw_rect(game->screen,
		(t_rect){SCREEN_WIDTH, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2},
		0x0087CEFA, 0);
	draw_rect(game->screen,
		(t_rect){SCREEN_WIDTH, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT / 2},
		0x00D4F1F4, 0);
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		m.ray_angle = fmod(start_angle + (i * angle_step), 360.0);
		m.inter = wall_inter(game, game->player.pos, m.ray_angle);
		put_wall_segment(game, &m, i);
		i += round(100 / TEXT_RES);
	}
	draw_flush(game);
}
