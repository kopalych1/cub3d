/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:05:42 by akostian          #+#    #+#             */
/*   Updated: 2025/06/11 12:22:51 by vcaratti         ###   ########.fr       */
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

char	*get_next_texture(t_cub_data *cub_data, int i)
{
	if (i == 0)
		return (cub_data->so_texture);
	if (i == 1)
		return (cub_data->no_texture);
	if (i == 2)
		return (cub_data->ea_texture);
	if (i == 3)
		return (cub_data->we_texture);
	return (NULL);
}

int	load_tex(t_game *game, t_cub_data *cub_data)
{
	int			i;

	i = -1;
	ft_memset(game->tex, 0, sizeof(game->tex));
	while (++i < 4)
	{
		game->tex[i].p = mlx_xpm_file_to_image(game->mlx_ptr,
				get_next_texture(cub_data, i),
				&(game->tex[i].width), &(game->tex[i].height));
		if (!game->tex[i].p)
			return (destroy_tex(game), 1);
	}
	return (0);
}
