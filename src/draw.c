/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:47:18 by akostian          #+#    #+#             */
/*   Updated: 2025/04/29 20:52:07 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_flush(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->screen, 0, 0);
}

/**
 * @brief Draws a pixel on the screen at the specified coordinates
 *        with the given color.
 *
 * @param	screen Pointer to the screen image structure (t_img)
 *                 where the pixel will be drawn.
 * @param	x      The x-coordinate of the pixel to be drawn.
 * @param	y      The y-coordinate of the pixel to be drawn.
 * @param	color  The color of the pixel in ARGB format.
 */
void	draw_pixel(t_img *screen, const int x, const int y, unsigned int color)
{
	const size_t	index = y * screen->size_line + (x * 4);

	if (screen->image->byte_order)
	{
		color = ((color >> 0) & 0xFF) << 24
			| ((color >> 8) & 0xFF) << 16
			| ((color >> 16) & 0xFF) << 8
			| ((color >> 24) & 0xFF);
		*(unsigned int *)(&screen->data[index]) = color;
	}
	else
	{
		*(unsigned int *)(&screen->data[index]) = color;
	}
}

/**
 * @brief Draws a rectangle in the game window.
 *
 * @param	screen       Pointer to the screen image
 *                       where the rectangle will be drawn.
 * @param	rect         Structure containing the rectangle's properties
 *                       (x, y, width, height).
 * @param	color        Fill color of the rectangle.
 * @param	border_color Border color of the rectangle
 *                       (0 if no border is needed).
 */
void	draw_rect(t_img *screen, t_rect rect,
	unsigned int color, unsigned int border_color)
{
	int	i;
	int	j;

	if ((rect.x < 0) || (rect.y < 0) || (rect.width < 0) || (rect.height < 0))
		return ;
	i = rect.y - 1;
	while (++i < rect.y + rect.height)
	{
		j = rect.x - 1;
		while (++j < rect.x + rect.width)
		{
			if (border_color
				&& ((i == rect.y) || (j == rect.x)
					|| (i == (rect.y + rect.height - 1))
					|| (j == (rect.x + rect.width - 1))))
			{
				draw_pixel(screen, j, i, border_color);
				continue ;
			}
			draw_pixel(screen, j, i, color);
		}
	}
}

/**
 * @brief	Draws a square using a t_square structure.
 *
 * @param	screen       Pointer to the screen image
 *                       where the rectangle will be drawn.
 * @param	sq           Structure containing square properties (x, y, side).
 * @param	color        Fill color of the square.
 * @param	border_color Border color of the square (0 if no border is needed).
 */
void	draw_square(t_img *screen, t_square sq,
	unsigned int color, unsigned int border_color)
{
	draw_rect(screen,
		(t_rect){sq.x, sq.y, sq.side, sq.side}, color, border_color);
}
