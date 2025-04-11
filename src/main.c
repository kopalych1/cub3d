/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:14:35 by akostian          #+#    #+#             */
/*   Updated: 2025/04/11 15:06:33 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_arr(char **arr, size_t size);

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 800

#define WALL_HEIGHT 200
#define TEXT_RES 100

#define KEY_PRESS_DISTANCE 0.5f
#define KEY_TURN_RATE 15.0f

#define PLAYER_WITDH 0.1

#define PLAYER_X 4
#define PLAYER_Y 4
#define PLAYER_ANGLE 90.0

#define FOV 60

void	exit_game(t_game *game)
{
	free_arr(game->map, game->map_height);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
}

int	on_destroy(t_game *game)
{
	exit_game(game);
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

#include "../minilibx-linux/mlx_int.h"

int	put_pixel(t_xvar *xvar, t_win_list *win,
		int x, int y, int color)
{
	XGCValues	xgcv;

	xgcv.foreground = mlx_int_get_good_color(xvar, color);
	XChangeGC(xvar->display, win->gc, GCForeground, &xgcv);
	XDrawPoint(xvar->display, win->window, win->gc, x, y);
	return (0);
}

/**
 * @brief	Draws a rectangle in the game window.
 *
 * @param	game         Pointer to the game structure.
 * @param	x            X-coordinate of the top-left corner of the rectangle.
 * @param	y            Y-coordinate of the top-left corner of the rectangle.
 * @param	width        Length of the rectangle's horisontal side.
 * @param	height       Length of the rectangle's vertical side.
 * @param	color        Fill color of the rectangle.
 * @param	border_color Border color of the rectangle (0 if no border is needed).
 */
void	draw_rect(t_game *game, const int x, const int y,
	const int width, const int height,
	unsigned int color, unsigned int border_color)
{
	const t_xvar		*xvar = game->mlx.mlx_ptr;
	const t_win_list	*win = game->mlx.win_ptr;
	XGCValues			xgcv1;
	XGCValues			xgcv2;
	unsigned int		curr_color = 0;

	if ((x < 0) || (y < 0) || (width < 0) || (height < 0))
		return ;
	xgcv1.foreground = mlx_int_get_good_color(xvar, color);
	if (border_color)
		xgcv2.foreground = mlx_int_get_good_color(xvar, border_color);
	for (int i = y; i < y + height; i++)
	{
		for (int j = x; j < x + width; j++)
		{
			if (border_color
				&& ((i == y) || (j == x)
					|| (i == (y + height - 1)) || (j == (x + width - 1))))
			{
				if (!curr_color || (curr_color != border_color))
				{
					curr_color = border_color;
					XChangeGC(xvar->display, win->gc, GCForeground, &xgcv2);
				}
				XDrawPoint(xvar->display, win->window, win->gc, j, i);
				continue;
			}
			if (!curr_color || (curr_color != color))
			{
				curr_color = color;
				XChangeGC(xvar->display, win->gc, GCForeground, &xgcv1);
			}
			XDrawPoint(xvar->display, win->window, win->gc, j, i);
		}
	}
}

/**
 * @brief	Draws a square in the game window.
 *
 * @param	game         Pointer to the game structure.
 * @param	x            X-coordinate of the top-left corner of the square.
 * @param	y            Y-coordinate of the top-left corner of the square.
 * @param	side         Length of the square's side.
 * @param	color        Fill color of the square.
 * @param	border_color Border color of the square (0 if no border is needed).
 */
void	draw_square(t_game *game, const int x, const int y,
	const int side, unsigned int color, unsigned int border_color)
{
	draw_rect(game, x, y, side, side, color, border_color);
}

void	draw_wall(t_game *game, const int x, const int y)
{
	draw_square(game, x * 50, y * 50, 50, 0x00999977, 0x007700a8);
}

void	draw_map(t_game *game)
{
	for (int i = 0; i < game->map_height; i++)
	{
		for (int j = 0; j < game->map_width; j++)
		{
			if (game->map[i][j] == '1')
				draw_wall(game, j, i);
			else
				draw_square(game, j * 50, i * 50, 50, 0x0, 0x00333333);
		}
	}
	draw_square(game, game->player.pos.x * 50 - 3, game->player.pos.y * 50 - 3, 5, 0x0000ff00, 0x0000ff00);
	XFlush(((t_xvar *)game->mlx.mlx_ptr)->display);
}

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

void	render(t_game *game)
{
	const double	start_angle = (game->player.angle - (FOV / 2) + 360);
	const double	angle_step = (float)FOV / ((float)SCREEN_WIDTH / 2);
	double			distance;
	double			ray_angle;

	draw_square(game, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, 0x00ffffff, 0x00ffffff);
	for (int i = 0; i < SCREEN_WIDTH / 2; i += round(100 / TEXT_RES))
	{
		ray_angle = fmod(start_angle + (i * angle_step), 360.0);
		distance = dist(
			game->player.pos,
			wall_inter(game, game->player.pos, ray_angle));
		distance *= cos(M_PI / 180 * (ray_angle - game->player.angle));
		draw_rect(game,
			SCREEN_WIDTH - i, constrain(
				round((SCREEN_HEIGHT / 2) - (WALL_HEIGHT / distance)),
				0, SCREEN_HEIGHT),
			round(100 / TEXT_RES), (WALL_HEIGHT / distance) * 2,
			0x0, 0x0);
	}
	XFlush(((t_xvar *)game->mlx.mlx_ptr)->display);
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

int main(int argc, char const *argv[])
{
	t_player	player = {{PLAYER_X, PLAYER_Y}, PLAYER_ANGLE};
	t_game		game;

	game.map_width = 0;
	game.map_height = 0;
	game.map = NULL;
	game.player = player;

	game.mlx.mlx_ptr = mlx_init();
	if (!game.mlx.mlx_ptr)
		return (1);
	game.mlx.win_ptr = mlx_new_window(game.mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game.mlx.win_ptr)
		return (1);

	if (get_map("maps/map.cub", &game))
		return (free_arr(game.map, game.map_height), printf("Map is not correct!\n"), 1);

	draw_map(&game);
	print_map(&game);

	mlx_hook(game.mlx.win_ptr, KeyPress, KeyPressMask, on_keypress, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, on_destroy, &game);
	mlx_loop(game.mlx.mlx_ptr);

	(void)argc;
	(void)argv;
	exit_game(&game);
	return (0);
}
