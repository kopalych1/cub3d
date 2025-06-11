/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 05:15:21 by akostian          #+#    #+#             */
/*   Updated: 2025/06/11 12:25:24 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_player_angle(t_game *game, t_cub_data *cub_data)
{
	if (cub_data->player.direction == 'N')
		game->player.angle = 90.0;
	else if (cub_data->player.direction == 'W')
		game->player.angle = 180.0;
	else if (cub_data->player.direction == 'S')
		game->player.angle = 270.0;
	else if (cub_data->player.direction == 'E')
		game->player.angle = 0.0;
}

int	create_trgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	set_trgb(t_game *game, t_cub_data *cub_data)
{
	game->ceiling_trgb = create_trgb(cub_data->ceiling_rgb[0],
			cub_data->ceiling_rgb[1], cub_data->ceiling_rgb[2]);
	game->floor_trgb = create_trgb(cub_data->floor_rgb[0],
			cub_data->floor_rgb[1], cub_data->floor_rgb[2]);
}

int	get_map(char *path, t_game *game)
{
	t_cub_data	cub_data;

	if (parsing(&cub_data, path))
		return (1);
	game->map_height = cub_data.height;
	game->map_width = cub_data.width;
	game->map = cub_data.map_c;
	cub_data.map_c = 0;
	game->player.pos.x = (double)cub_data.player.x + 0.5;
	game->player.pos.y = (double)cub_data.player.y + 0.5;
	if (load_tex(game, &cub_data))
		return (free_all(NULL, &cub_data), 1);
	set_trgb(game, &cub_data);
	set_player_angle(game, &cub_data);
	free_all(NULL, &cub_data);
	return (0);
}

int	init(t_game *game, char *path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ENOMEM);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game->win_ptr)
		return (free_game(game), ENOMEM);
	game->screen = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->screen)
		return (free_game(game), ENOMEM);
	if (get_map(path, game))
	{
		free_game(game);
		return (1);
	}
	return (0);
}
