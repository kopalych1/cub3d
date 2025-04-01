/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:55:52 by akostian          #+#    #+#             */
/*   Updated: 2025/04/01 21:41:43 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

# include "control_keys.h"

# include <stdio.h>
# include <math.h>

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
}	t_player;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	t_player	player;
	t_mlx		mlx;
}	t_game;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

int	is_control_key(int keysym);

#endif