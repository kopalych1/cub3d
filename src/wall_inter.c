/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:31:42 by akostian          #+#    #+#             */
/*   Updated: 2025/04/28 04:10:45 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_check_cords(t_wall_math *m, int *check_x, int *check_y)
{
	if (m->intersection_type == 3)
	{
		*check_x = round(m->pos.x) - (m->dy < 0);
		*check_y = round(m->pos.y) - (m->dx < 0);
	}
	else if (m->intersection_type == 1)
	{
		if (m->dy > 0)
			*check_x = (int)m->pos.x;
		else
			*check_x = (int)m->pos.x - 1;
		*check_y = (int)m->pos.y;
	}
	else if (m->intersection_type == 2)
	{
		*check_x = (int)m->pos.x;
		if (m->dx > 0)
			*check_y = (int)m->pos.y;
		else
			*check_y = (int)m->pos.y - 1;
	}
}

static int	check_wall(t_wall_math *m)
{
	int	check_x;
	int	check_y;

	check_x = 0;
	check_y = 0;
	set_check_cords(m, &check_x, &check_y);
	check_x = constrain(check_x, 0, m->game->map_width - 1);
	check_y = constrain(check_y, 0, m->game->map_height - 1);
	if (m->intersection_type && (m->game->map[check_y][check_x] == '1'))
		return (1);
	return (0);
}

static void	next_inter(t_wall_math *m)
{
	if (fabs(dist(m->pos, m->inter_x) - dist(m->pos, m->inter_y))
		< 0.000002f)
	{
		m->pos = m->inter_x;
		m->next_x += (m->dy > 0) - !(m->dy > 0);
		m->next_y += (m->dx > 0) - !(m->dx > 0);
		m->intersection_type = 3;
	}
	else if (dist(m->pos, m->inter_x) < dist(m->pos, m->inter_y))
	{
		m->pos = m->inter_x;
		m->next_x += (m->dy > 0) - !(m->dy > 0);
		m->intersection_type = 1;
	}
	else
	{
		m->pos = m->inter_y;
		m->next_y += (m->dx > 0) - !(m->dx > 0);
		m->intersection_type = 2;
	}
}

static void	init_m(t_game *game, t_wall_math *m, t_point pos0, double angle)
{
	const short		dx_sign = 1 - (2 * (angle <= 90 || angle >= 270));
	const short		dy_sign = 1 - (2 * (angle >= 180));

	m->game = game;
	m->dx = dx_sign * tan(M_PI / 180 * angle);
	m->dy = dy_sign * tan(M_PI / 180 * (90 - angle));
	m->pos = pos0;
	if (fabs(fmod(angle, 90)) < 0.000002f)
	{
		m->dx = (angle > 269 && angle < 271) - (angle > 89 && angle < 91);
		m->dy = (angle >= 0 && angle < 1) - (angle > 179 && angle < 181);
	}
	m->next_x = ((m->dy > 0) * ((int)m->pos.x + 1))
		+ (!(m->dy >= 0) * (ceil(m->pos.x) - 1));
	m->next_y = ((m->dx > 0) * ((int)m->pos.y + 1))
		+ (!(m->dx >= 0) * (ceil(m->pos.y) - 1));
	m->intersection_type = 0;
}

/**
 * @brief	wall_inter - Calculates the coordinates of intersection
 * with the nearest wall from a point in a given direction (angle).
 * 
 * @param	game  Pointer to the game structure
 * @param	point the point
 * @param	angle The angle (in degrees) at which the ray is cast from
 * 
 * @return	The coordinates of intersection with the nearest wall.
*/
t_point	wall_inter(t_game *game, const t_point pos0, double angle)
{
	t_wall_math	m;

	init_m(game, &m, pos0, angle);
	while (1)
	{
		m.inter_x.x = m.next_x;
		m.inter_x.y = pos0.y + m.dx * fabs(pos0.x - m.next_x);
		m.inter_y.x = pos0.x + m.dy * fabs(pos0.y - m.next_y);
		m.inter_y.y = m.next_y;
		draw_square(game->screen,
			(t_square){(int)(m.pos.x * 50), (int)(m.pos.y * 50), 1},
			0x00dd0000, 0x0);
		if (check_wall(&m))
			break ;
		next_inter(&m);
	}
	return (m.pos);
}
