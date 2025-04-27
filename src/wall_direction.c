/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:10:27 by akostian          #+#    #+#             */
/*   Updated: 2025/04/26 05:24:51 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief Determines the direction of the wall hit by a ray.
 * 
 * @param pos   The intersection point where the ray hits the wall.
 * @param angle The angle of the ray in degrees.
 * 
 * @return The direction of the wall hit.
 */
enum e_direction	wall_direction(t_point pos, double angle)
{
	const unsigned char		is_corner = ((pos.x - floor(pos.x)) < 0.000002f)
		&& ((pos.y - floor(pos.y)) < 0.000002f);
	static enum e_direction	previous_dir;

	if (is_corner)
		return (previous_dir);
	if ((pos.x - floor(pos.x)) < 0.000002f)
	{
		if (angle > 90 && angle < 270)
			return (previous_dir = EAST, EAST);
		return (previous_dir = WEST, WEST);
	}
	if (angle > 0 && angle < 180)
		return (previous_dir = SOUTH, SOUTH);
	return (previous_dir = NORTH, NORTH);
}
