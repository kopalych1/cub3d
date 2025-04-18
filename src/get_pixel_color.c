/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:56:54 by akostian          #+#    #+#             */
/*   Updated: 2025/04/19 01:16:04 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief Get the color of a specific pixel on t_img
 * 
 * @param	img Pointer to the image structure.
 * @param	x   X-coordinate of the pixel to retrieve.
 * @param	y   Y-coordinate of the pixel to retrieve.
 * 
 * @return The color of the pixel as a 32-bit hexadecimal value (ARGB format).
 */
unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	const int			line_bytes = img->size_line;
	const int			endian = img->image->byte_order;
	const unsigned char	*buffer = (unsigned char *)img->data;
	unsigned int		color;

	color = 0;
	if (endian)
	{
		color += (buffer[y * line_bytes + ((int)x * 4) + 0]) << 24;
		color += (buffer[y * line_bytes + ((int)x * 4) + 1]) << 16;
		color += (buffer[y * line_bytes + ((int)x * 4) + 2]) << 8;
		color += (buffer[y * line_bytes + ((int)x * 4) + 3]) << 0;
	}
	else
	{
		color += (buffer[y * line_bytes + ((int)x * 4) + 0]) << 0;
		color += (buffer[y * line_bytes + ((int)x * 4) + 1]) << 8;
		color += (buffer[y * line_bytes + ((int)x * 4) + 2]) << 16;
		color += (buffer[y * line_bytes + ((int)x * 4) + 3]) << 24;
	}
	return (color);
}
