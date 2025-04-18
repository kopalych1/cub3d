/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:05:42 by akostian          #+#    #+#             */
/*   Updated: 2025/04/19 01:16:47 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	load_tex(t_game *game)
{
	game->tex.width = TEX_WIDTH;
	game->tex.height = TEX_HEIGHT;
	game->tex.n_wall = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"textures/brick_wall_64x64.xpm",
			&game->tex.width, &game->tex.height);
	if (!game->tex.n_wall)
		return (1);
	game->tex.s_wall = NULL;
	game->tex.w_wall = NULL;
	game->tex.e_wall = NULL;
	return (0);
}
