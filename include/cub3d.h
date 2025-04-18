/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:55:52 by akostian          #+#    #+#             */
/*   Updated: 2025/04/19 01:17:34 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "control_keys.h"

# include <stdio.h>
# include <math.h>

/* ========== Math ========== */

typedef struct s_game	t_game;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

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

int					constrain(int x, int a, int b);
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

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_textures
{
	void	*n_wall;
	void	*s_wall;
	void	*w_wall;
	void	*e_wall;
	int		width;
	int		height;
}	t_textures;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	t_player	player;
	t_mlx		mlx;
	t_textures	tex;
}	t_game;

enum e_mlx_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

int					load_tex(t_game *game);
unsigned int		get_pixel_color(t_img *img, int x, int y);

int					is_control_key(int keysym);

void				draw_square(t_game *game, const int x, const int y,
						const int side,
						unsigned int color, unsigned int border_color);

#endif