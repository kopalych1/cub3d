/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:48:42 by vcaratti          #+#    #+#             */
/*   Updated: 2025/03/19 13:17:48 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSER_H__
#define __PARSER_H__

#include "get_next_line.h"

typedef struct s_node
{
	struct s_node	prev;
	struct s_node	next;
	char		*line;
}	t_node;

typedef struct s_cub_data
{
	bool	map_closed;
	t_node	*map_start;
	char	*SO_texture;
	char	*NO_texture;
	char	*WE_texture;
	char	*EA_texture;
	int	ceiling_rgb[3];
	int	floor_rgb[3];
}	t_cub_data;

typedef struct s_processing
{
	int	fd;
	int	(*processes[3](char *line, t_cub_data *cub_data));

}	t_processing;

#endif
