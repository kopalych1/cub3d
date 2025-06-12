/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:12:06 by akostian          #+#    #+#             */
/*   Updated: 2025/06/12 10:58:15 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_side(t_game *game, double angle)
{
	game->player.pos.x = fconstrain(
			game->player.pos.x - cos(M_PI / 180 * (game->player.angle + angle))
			* KEY_PRESS_DISTANCE, 0, game->map_width - 1);
	game->player.pos.y = fconstrain(
			game->player.pos.y + sin(M_PI / 180 * (game->player.angle + angle))
			* KEY_PRESS_DISTANCE, 0, game->map_height - 1);
}

static void	move_forbackward(t_game *game, short dir)
{
	game->player.pos.x = fconstrain(
			game->player.pos.x + cos(M_PI / 180 * game->player.angle)
			* KEY_PRESS_DISTANCE * dir, 0, game->map_width - 1);
	game->player.pos.y = fconstrain(
			game->player.pos.y - sin(M_PI / 180 * game->player.angle)
			* KEY_PRESS_DISTANCE * dir, 0, game->map_height - 1);
}

int	move_player(t_game *game, int keysym)
{
	if (keysym == D_KEY)
		move_side(game, 90);
	else if (keysym == A_KEY)
		move_side(game, -90);
	else if (keysym == W_KEY)
		move_forbackward(game, 1);
	else if (keysym == S_KEY)
		move_forbackward(game, -1);
	else if (keysym == LEFT_ARROW_KEY)
		game->player.angle = fmod(game->player.angle + KEY_TURN_RATE, 360.0);
	else if (keysym == RIGHT_ARROW_KEY)
		game->player.angle
			= fmod(game->player.angle - KEY_TURN_RATE + 360.0, 360.0);
	return (0);
}
