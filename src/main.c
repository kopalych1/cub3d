/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:14:35 by akostian          #+#    #+#             */
/*   Updated: 2025/06/11 12:27:17 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_game(t_game *game)
{
	destroy_tex(game);
	if (game->screen)
		mlx_destroy_image(game->mlx_ptr, game->screen);
	if (game->map)
		free_arr(game->map, game->map_height);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

int	on_destroy(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == Q_KEY || keysym == ESC_KEY)
		on_destroy(game);
	if (!is_control_key(keysym))
		return (0);
	move_player(game, keysym);
	render(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (init(&game, argv[1]))
		return (ENOMEM);
	render(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, NoEventMask, on_destroy, &game);
	mlx_loop(game.mlx_ptr);
	(void)argc;
	free_game(&game);
	return (0);
}
