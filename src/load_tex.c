/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:05:42 by akostian          #+#    #+#             */
/*   Updated: 2025/06/12 14:08:34 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	destroy_tex(t_game *game)
{
	if (game->tex[NORTH].p)
		mlx_destroy_image(game->mlx_ptr, game->tex[NORTH].p);
	if (game->tex[SOUTH].p)
		mlx_destroy_image(game->mlx_ptr, game->tex[SOUTH].p);
	if (game->tex[WEST].p)
		mlx_destroy_image(game->mlx_ptr, game->tex[WEST].p);
	if (game->tex[EAST].p)
		mlx_destroy_image(game->mlx_ptr, game->tex[EAST].p);
}

int	load_tex(t_game *game, t_cub_data *cub_data)
{
	const char	*err = "Error: Loading textures\n";
	int			i;

	i = -1;
	ft_memset(game->tex, 0, sizeof(game->tex));
	while (++i < 4)
	{
		game->tex[i].p = mlx_xpm_file_to_image(game->mlx_ptr,
				cub_data->tex_paths[i],
				&(game->tex[i].width), &(game->tex[i].height));
		if (!game->tex[i].p)
		{
			if (write(2, err, ft_strlen(err)))
			{
			}
			return (destroy_tex(game), 1);
		}
	}
	return (0);
}
