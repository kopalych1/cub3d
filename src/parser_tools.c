/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:49:09 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/12 13:51:38 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	set_error(t_cub_data *cub_data, int error)
{
	cub_data->error = error;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned long	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i] != 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

int	ft_arr_len(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	*line_to_int_arr(char *line, int width)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * width);
	if (!ret)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == 9)
			ret[i] = -1;
		else if (line[i] == '0')
			ret[i] = 0;
		else if (line[i] == '1')
			ret[i] = 1;
		else if (line[i] == '2')
			ret[i] = 2;
		else
			return (NULL);
		i++;
	}
	while (i < width)
		ret[i++] = -1;
	return (ret);
}

void	init_data(t_cub_data *c, t_node *map_head, t_node *list_head)
{
	ft_memset(c, 0, sizeof(t_cub_data));
	ft_memset(map_head, 0, sizeof(t_node));
	ft_memset(list_head, 0, sizeof(t_node));
}
