/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 05:15:21 by akostian          #+#    #+#             */
/*   Updated: 2025/04/29 20:36:31 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_map(char *path, t_game *game)
{
	const int	fd = open(path, O_RDONLY);
	char		*line;
	int			height;

	height = 0;
	line = get_next_line(fd);
	game->map_width = ft_strlen(line) - (ft_strchr(line, '\n') != NULL);
	while (line)
	{
		height++;
		game->map_height++;
		game->map = ft_realloc(game->map, (height - 1) * sizeof(char *),
				height * sizeof(char *));
		line[ft_strlen(line) - (ft_strchr(line, '\n') != NULL)] = '\0';
		game->map[height - 1] = line;
		if ((int)(ft_strlen(line) - (ft_strchr(line, '\n') != NULL))
			!= game->map_width)
			return (1);
		line = get_next_line(fd);
	}
	return (0);
}

int	init(t_game *game)
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
	if (load_tex(game))
		return (free_game(game), ENOMEM);
	// TO BE CHANGED WHEN PARSING PART READY
	if (get_map("maps/map.cub", game))
	{
		free_game(game);
		return (printf("Map is not correct!\n"), 1);
	}
	return (0);
}
