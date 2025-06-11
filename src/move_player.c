/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:12:06 by akostian          #+#    #+#             */
/*   Updated: 2025/05/02 06:14:37 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_side(t_player *player, double angle)
{
	player->pos.x -= cos(M_PI / 180 * (player->angle + angle))
		* KEY_PRESS_DISTANCE;
	player->pos.y += sin(M_PI / 180 * (player->angle + angle))
		* KEY_PRESS_DISTANCE;
}

static void	move_forbackward(t_player *player, short dir)
{
	player->pos.x += cos(M_PI / 180 * player->angle) * KEY_PRESS_DISTANCE * dir;
	player->pos.y -= sin(M_PI / 180 * player->angle) * KEY_PRESS_DISTANCE * dir;
}

int	move_player(t_game *game, int keysym)
{
	if (keysym == D_KEY)
		move_side(&game->player, 90);
	else if (keysym == A_KEY)
		move_side(&game->player, -90);
	else if (keysym == W_KEY)
		move_forbackward(&game->player, 1);
	else if (keysym == S_KEY)
		move_forbackward(&game->player, -1);
	else if (keysym == LEFT_ARROW_KEY)
		game->player.angle = fmod(game->player.angle + KEY_TURN_RATE, 360.0);
	else if (keysym == RIGHT_ARROW_KEY)
		game->player.angle
			= fmod(game->player.angle - KEY_TURN_RATE + 360.0, 360.0);
	return (0);
}
