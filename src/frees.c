/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:34:20 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/10 13:56:25 by vcaratti         ###   ########.fr       */
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
	free(cub_data->so_texture);
	free(cub_data->no_texture);
	free(cub_data->we_texture);
	free(cub_data->ea_texture);
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
