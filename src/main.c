/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:14:35 by akostian          #+#    #+#             */
/*   Updated: 2025/04/01 08:52:23 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_arr(char **arr, size_t size);

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#define PLAYER_X 4
#define PLAYER_Y 4
#define PLAYER_ANGLE 90.0

#define FOV 90

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
			else if (((game->player.x - 0.5f) >= j && (game->player.x - 0.5f) < (j + 1))
				&& ((game->player.y - 0.5f) >= i && (game->player.y - 0.5f) < (i + 1))
			)
				printf("%s ", angle_str(PLAYER_ANGLE));
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
	t_xvar		*xvar = game->mlx.mlx_ptr;
	t_win_list	*win = game->mlx.win_ptr;
	XGCValues	xgcv1;
	XGCValues	xgcv2;

	xgcv1.foreground = mlx_int_get_good_color(xvar, color);
	if (border_color)
		xgcv2.foreground = mlx_int_get_good_color(xvar, border_color);
	for (int i = y; i < y + side; i++)
	{
		for (int j = x; j < x + side; j++)
		{
			if (border_color
				&& ((i == y) || (j == x)
					|| (i == (y + side - 1)) || (j == (x + side - 1))))
			{
				XChangeGC(xvar->display, win->gc, GCForeground, &xgcv2);
				XDrawPoint(xvar->display, win->window, win->gc, j, i);
			}
			else
			{
				XChangeGC(xvar->display, win->gc, GCForeground, &xgcv1);
				XDrawPoint(xvar->display, win->window, win->gc, j, i);
			}
		}
	}
}

void	draw_wall(t_game *game, const int x, const int y)
{
	draw_square(game, x * 50, y * 50, 50, 0x00999977, 0x007700a8);
}

/**
 * @brief	Calculates the Euclidean distance between two points.
 *
 * @param	p1 First point.
 * @param	p2 Second point.
 * @return	The Euclidean distance between p1 and p2.
 */
double	dist(t_point p1, t_point p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

/**
 * @brief	calc_distance - Calculates the distance from the player to the
 * nearest wall in a given direction (angle).
 * 
 * @param	game  Pointer to the game structure
 * @param	angle The angle (in degrees) at which the ray is cast from
 * the player's position.
 * 
 * @return	The distance from the player's position to the nearest wall.
*/
float	calc_distance(t_game *game, float angle)
{
	// TODO: 90 180 270 360 deg angles
	float			distance;
	const short		dx_sign = 1 - (2 * (angle <= 90 || angle >= 270));
	const short		dy_sign = 1 - (2 * (angle >= 180));
	const float		dx = dx_sign * tanf(M_PI / 180 * angle);
	const float		dy = dy_sign * tanf(M_PI / 180 * (90 - angle));
	const t_point	pos0 = {game->player.x, game->player.y};
	t_point			pos;

	pos.x = game->player.x;
	pos.y = game->player.y;

	int	next_x = ((dy > 0) * ((int)pos.x + 1)) + (!(dy > 0) * (ceil(pos.x) - 1));
	int	next_y = ((dx > 0) * ((int)pos.y + 1)) + (!(dx > 0) * (ceil(pos.y) - 1));

	distance = 0;

	int	check_x = 0;
	int	check_y = 0;

	short	intersection_type = 0;

	while (1)
	{
		// printf("-------------------------------------------\n");
		t_point	intersection_x;
		t_point	intersection_y;

		intersection_x.x = next_x;
		intersection_x.y = pos0.y + dx * fabs(pos0.x - next_x);
		intersection_y.x = pos0.x + dy * fabs(pos0.y - next_y);
		intersection_y.y = next_y;

		// printf("pos.x=%f\n", pos.x);
		// printf("pos.y=%f\n", pos.y);

		// Red dot of intersection
		draw_square(game, (int)(pos.x * 50) - 2, (int)(pos.y * 50) - 2, 3,
			0x00dd0000, 0x0);

		if (intersection_type == 3)
		{
			check_x = (int)pos.x - (dy < 0);
			check_y = (int)pos.y - (dx < 0) + ((dy < 0) && (dx > 0));
		}
		else if (intersection_type == 1)
		{
			if (dy > 0)
				check_x = (int)pos.x;
			else
				check_x = (int)pos.x - 1;
			check_y = (int)pos.y;
		}
		else if (intersection_type == 2)
		{
			check_x = (int)pos.x;
			if (dx > 0)
				check_y = (int)pos.y;
			else
				check_y = (int)pos.y - 1;
		}
		if (intersection_type && (game->map[check_y][check_x] == '1'))
			break ;

		// Step to the next intersection
		if (fabs(dist(pos, intersection_x) - dist(pos, intersection_y))
			< 0.000002f)
		{
			distance += dist(pos, intersection_x);

			pos.x = intersection_x.x;
			pos.y = intersection_x.y;

			next_x += (dy > 0) - !(dy > 0);
			next_y += (dx > 0) - !(dx > 0);

			intersection_type = 3;
		}
		else if (dist(pos, intersection_x) < dist(pos, intersection_y))
		{
			distance += dist(pos, intersection_x);

			pos.x = intersection_x.x;
			pos.y = intersection_x.y;

			next_x += (dy > 0) - !(dy > 0);

			intersection_type = 1;
		}
		else
		{
			distance += dist(pos, intersection_y);

			pos.x = intersection_y.x;
			pos.y = intersection_y.y;

			next_y += (dx > 0) - !(dx > 0);

			intersection_type = 2;
		}

		// XFlush(((t_xvar *)game->mlx.mlx_ptr)->display);
		usleep(5 * 1000);
	}

	// Last wall square
	draw_square(game, check_x * 50, check_y * 50, 50, 0x0,
		0x0022dd00);
	draw_square(game, check_x * 50 + 1, check_y * 50 + 1, 48,
		0x0, 0x0022dd00);
	draw_square(game, check_x * 50 + 2, check_y * 50 + 2, 46,
		0x00999977, 0x00999977);

	// Last intersection
	draw_square(game, (int)(pos.x * 50) - 2, (int)(pos.y * 50) - 2, 3,
		0x00ff00ff, 0x0);

	// printf("Found wall(%d, %d) at (%f, %f)\n", check_x, check_y, pos.x, pos.y);
	// printf("distance=%f\n", distance);

	XFlush(((t_xvar *)game->mlx.mlx_ptr)->display);

	return (distance);
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
	draw_square(game, game->player.x * 50 - 3, game->player.y * 50 - 3, 5, 0x0000ff00, 0x0000ff00);
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


int main(int argc, char const *argv[])
{
	t_player	player;
	t_game		game;

	game.map_width = 0;
	game.map_height = 0;
	game.map = NULL;
	player.x = PLAYER_X;
	player.y = PLAYER_Y;
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

	for (float i = 0; i < 361; i += 1)
	{
		if (((int)i % 90 != 0))
			calc_distance(&game, i);
	}

	mlx_hook(game.mlx.win_ptr, 17, 0, on_destroy, &game);
	mlx_loop(game.mlx.mlx_ptr);

	(void)argc;
	(void)argv;
	exit_game(&game);
	return (0);
}
