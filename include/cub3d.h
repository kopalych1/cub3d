/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:55:52 by akostian          #+#    #+#             */
/*   Updated: 2025/06/12 10:47:59 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "control_keys.h"

# include "parser.h"

# include <stdio.h>
# include <math.h>
# include <errno.h>

# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 1000

# define WALL_HEIGHT 500
# define TEXT_RES 100
# define FOV 60

# define KEY_PRESS_DISTANCE 0.5f
# define KEY_TURN_RATE 15.0f

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

/* ========== Math ========== */

typedef struct s_game	t_game;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_rect
{
	int		x;		// X-coordinate of the top-left corner of the rectangle.
	int		y;		// Y-coordinate of the top-left corner of the rectangle.
	int		width;	// Length of the rectangle's horisontal side.
	int		height;	// Length of the rectangle's vertical side.
}	t_rect;

typedef struct s_square
{
	int		x;		// X-coordinate of the top-left corner of the square.
	int		y;		// Y-coordinate of the top-left corner of the square.
	int		side;	// Length of the square's side.
}	t_square;

typedef struct s_wall_math
{
	double		dx;
	double		dy;
	t_game		*game;
	t_point		pos;
	int			next_x;
	int			next_y;
	short		intersection_type;
	t_point		inter_x;
	t_point		inter_y;
}	t_wall_math;

typedef struct s_draw_math
{
	double				ray_angle;
	t_point				inter;
	double				distance;
	int					tex_x;
	int					tex_y;
	int					screen_x;
	int					screen_y;
	enum e_direction	dir;
	int					wall_height;
}	t_draw_math;

int					constrain(int x, int a, int b);
double				fconstrain(double x, double a, double b);
double				dist(t_point p1, t_point p2);
t_point				wall_inter(t_game *game, const t_point pos0, double angle);
enum e_direction	wall_direction(t_point pos, double angle);

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_player
{
	t_point	pos;
	float	angle;
}	t_player;

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_tex
{
	void	*p;
	int		width;
	int		height;
}	t_tex;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	int			ceiling_trgb;
	int			floor_trgb;
	t_player	player;
	void		*mlx_ptr;
	void		*win_ptr;
	t_tex		tex[4];
	t_img		*screen;
}	t_game;

void				free_game(t_game *game);
void				destroy_tex(t_game *game);

int					init(t_game *game, char *path);

int					load_tex(t_game *game, t_cub_data *cub_data);
unsigned int		get_pixel_color(t_img *img, int x, int y);

void				render(t_game *game);

int					move_player(t_game *game, int keysym);
int					is_control_key(int keysym);

void				draw_flush(t_game *game);
void				draw_pixel(t_img *screen, const int x, const int y,
						unsigned int color);
void				draw_rect(t_img *screen, t_rect rect,
						unsigned int color, unsigned int border_color);
void				draw_square(t_img *screen, t_square sq,
						unsigned int color, unsigned int border_color);

void				free_arr(char **arr, size_t size);

#endif
