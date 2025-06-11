/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:38:13 by akostian          #+#    #+#             */
/*   Updated: 2025/04/09 19:19:56 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief	Constrains a number to be within a range
 * 
 * @param	x The number to constrain.
 * @param	a The lower end of the range.
 * @param	b The upper end of the range.
 */
int	constrain(int x, int a, int b)
{
	if (x < a)
		return (a);
	if (x > b)
		return (b);
	return (x);
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

void	free_arr(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}
