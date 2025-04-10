/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_control_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 03:23:34 by akostian          #+#    #+#             */
/*   Updated: 2025/04/01 21:24:36 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_control_key(int keysym)
{
	return (keysym == D_KEY || keysym == RIGHT_ARROW_KEY
		|| keysym == A_KEY || keysym == LEFT_ARROW_KEY
		|| keysym == S_KEY || keysym == DOWN_ARROW_KEY
		|| keysym == W_KEY || keysym == UP_ARROW_KEY
		|| keysym == Q_KEY || keysym == ESC_KEY);
}
