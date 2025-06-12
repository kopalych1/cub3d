/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:34:20 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/12 13:50:23 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	free_map_i(t_cub_data *cub_data)
{
	int	i;

	i = 0;
	if (cub_data->map_i)
	{
		while (cub_data->map_i[i])
			free(cub_data->map_i[i++]);
		free(cub_data->map_i);
	}
	cub_data->map_i = NULL;
}

void	free_all(t_node *list_head, t_cub_data *cub_data)
{
	int	i;

	free_list(list_head);
	free_list(&cub_data->map_head);
	i = 0;
	while (i < 4)
		free(cub_data->tex_paths[i++]);
	i = 0;
	free_map_i(cub_data);
	if (cub_data->map_c)
	{
		while (cub_data->map_c[i])
			free(cub_data->map_c[i++]);
		free(cub_data->map_c);
	}
}

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_until(char **map_c, int i)
{
	while (--i >= 0)
		free(map_c[i]);
}
