/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:14:35 by akostian          #+#    #+#             */
/*   Updated: 2025/04/29 22:32:38 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_arr(char **arr, size_t size);

#define WALL_HEIGHT 350
#define TEXT_RES 100

#define KEY_PRESS_DISTANCE 0.5f
#define KEY_TURN_RATE 15.0f

#define PLAYER_WITDH 0.1

#define PLAYER_X 4
#define PLAYER_Y 4
#define PLAYER_ANGLE 90.0

#define FOV 60

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

char	*angle_str(float angle)
{
	if (angle >= 45 && angle <= (90 + 45))
		return ("↑");
	if (angle >= (90 + 45) && angle <= (180 + 45))
		return ("←");
	if (angle >= (180 + 45) && angle <= (270 + 45))
		return ("↓");
	return ("→");
}

void	print_map(t_game *game)
{
	for (int i = 0; i < game->map_height; i++)
	{
		for (int j = 0; j < game->map_width; j++)
		{
			if (game->map[i][j] == '1')
				printf("%c ", game->map[i][j]);
			else if (((game->player.pos.x - 0.5f) >= j
					&& (game->player.pos.x - 0.5f) < (j + 1))
				&& ((game->player.pos.y - 0.5f) >= i
					&& (game->player.pos.y - 0.5f) < (i + 1))
			)
				printf("%s ", angle_str(game->player.angle));
			else
				printf("%c ", game->map[i][j]);
		}
		printf("\n");
	}
}

void	draw_map(t_game *game)
{
	for (int i = 0; i < game->map_height; i++)
	{
		for (int j = 0; j < game->map_width; j++)
		{
			if (game->map[i][j] == '1')
				draw_square(game->screen, (t_square){j * 50, i * 50, 50},
					0x00999977, 0x007700a8);
			else
				draw_square(game->screen, (t_square){j * 50, i * 50, 50},
					0, 0x00333333);
		}
	}
	draw_square(game->screen,
		(t_square){
		game->player.pos.x * 50 - 3,
		game->player.pos.y * 50 - 3,
		5},
		0x0000ff00, 0x0000ff00);
}

/**
 * @brief Calculates the wall position offset for texture mapping.
 * 
 * @param p   The point on the wall.
 * @param dir The direction of the wall (NORTH, SOUTH, EAST, or WEST).
 * 
 * @return The fractional offset of the point along the wall.
 */
double	wall_pos(t_point p, enum e_direction dir)
{
	if (dir == NORTH || dir == SOUTH)
		return (ceil(p.x) - p.x);
	return (ceil(p.y) - p.y);
}

static void	put_wall_segment(
	t_game *game, t_draw_math *m, int i
)
{
	m->distance = dist(game->player.pos, m->inter)
		* cos(M_PI / 180 * (m->ray_angle - game->player.angle));
	m->wall_height = round(WALL_HEIGHT / m->distance);
	for (int j = 0; j < m->wall_height; j++)
	{
		m->screen_x = SCREEN_WIDTH - i;
		m->screen_y = (SCREEN_HEIGHT - m->wall_height) / 2 + j;
		if ((m->screen_y <= 0)
			|| (m->screen_y > SCREEN_HEIGHT))
			continue;
		m->dir = wall_direction(m->inter, m->ray_angle);
		m->tex_x = wall_pos(m->inter, m->dir) * game->tex[m->dir].width;
		m->tex_y = floor((double)j / (double)m->wall_height * (double)game->tex[m->dir].height);
		draw_pixel(game->screen,
			m->screen_x, m->screen_y,
			get_pixel_color(game->tex[m->dir].p, m->tex_x, m->tex_y));
	}
}

void	render(t_game *game)
{
	const double	start_angle = (game->player.angle - (FOV / 2) + 360);
	const double	angle_step = (float)FOV / ((float)SCREEN_WIDTH / 2);
	t_draw_math		m;

	draw_rect(game->screen,
		(t_rect){SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2},
		0x0087CEFA, 0);
	draw_rect(game->screen,
		(t_rect){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2},
		0x00D4F1F4, 0);
	for (int i = 0; i < SCREEN_WIDTH / 2; i += round(100 / TEXT_RES))
	{
		m.ray_angle = fmod(start_angle + (i * angle_step), 360.0);
		m.inter = wall_inter(game, game->player.pos, m.ray_angle);
		put_wall_segment(game, &m, i);
	}
	draw_flush(game);
}

int	move_player(t_game *game, int keysym)
{
	//TODO: Wall collision
	if (keysym == D_KEY)
	{
		game->player.pos.x -= cos(M_PI / 180 * (game->player.angle + 90)) * KEY_PRESS_DISTANCE;
		game->player.pos.y += sin(M_PI / 180 * (game->player.angle + 90)) * KEY_PRESS_DISTANCE;
	}
	if (keysym == A_KEY)
	{
		game->player.pos.x -= cos(M_PI / 180 * (game->player.angle - 90)) * KEY_PRESS_DISTANCE;
		game->player.pos.y += sin(M_PI / 180 * (game->player.angle - 90)) * KEY_PRESS_DISTANCE;
	}
	if (keysym == S_KEY)
	{
		game->player.pos.x -= cos(M_PI / 180 * game->player.angle) * KEY_PRESS_DISTANCE;
		game->player.pos.y += sin(M_PI / 180 * game->player.angle) * KEY_PRESS_DISTANCE;
	}
	if (keysym == W_KEY)
	{
		game->player.pos.x += cos(M_PI / 180 * game->player.angle) * KEY_PRESS_DISTANCE;
		game->player.pos.y -= sin(M_PI / 180 * game->player.angle) * KEY_PRESS_DISTANCE;
	}
	if (keysym == LEFT_ARROW_KEY)
	{
		game->player.angle = fmod(game->player.angle + KEY_TURN_RATE, 360.0);
	}
	if (keysym == RIGHT_ARROW_KEY)
	{
		game->player.angle = fmod(game->player.angle - KEY_TURN_RATE + 360.0, 360.0);
	}
	return (0);
}

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == Q_KEY || keysym == ESC_KEY)
		on_destroy(game);
	if (!is_control_key(keysym))
		return (0);
	move_player(game, keysym);
	draw_map(game);
	render(game);
	return (0);
}

int	main(int argc, char const **argv)
{
	t_game	game;

	if (init(&game))
		return (ENOMEM);
	game.player = (t_player){{PLAYER_X, PLAYER_Y}, PLAYER_ANGLE};
	print_map(&game);
	draw_map(&game);
	render(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, NoEventMask, on_destroy, &game);
	mlx_loop(game.mlx_ptr);
	(void)argc;
	(void)argv;
	free_game(&game);
	return (0);
}
