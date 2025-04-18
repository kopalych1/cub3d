/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:10:27 by akostian          #+#    #+#             */
/*   Updated: 2025/04/19 01:15:02 by akostian         ###   ########.fr       */
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
	if ((pos.x - floor(pos.x)) < 0.000002f)
	{
		if (angle > 90 && angle < 270)
			return (EAST);
		return (WEST);
	}
	if (angle > 0 && angle < 180)
		return (SOUTH);
	return (NORTH);
}
