/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:48:42 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/11 12:26:45 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/include/libft.h"
# include "fcntl.h"
# include "stdio.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	char			*line;
}	t_node;

typedef struct s_player_pars
{
	int		x;
	int		y;
	char	direction;
}	t_player_pars;

typedef struct s_cub_data
{
	int				error;
	int				width;
	int				height;
	t_node			map_head;
	t_player_pars	player;
	int				**map_i;
	char			**map_c;
	char			*so_texture;
	char			*no_texture;
	char			*we_texture;
	char			*ea_texture;
	int				ceiling_rgb[3];
	int				floor_rgb[3];
}	t_cub_data;

//	parser_tools.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_arr_len(char **array);
int		*line_to_int_arr(char *line, int width);
void	init_data(t_cub_data *c, t_node *map_head, t_node *list_head);
void	set_error(t_cub_data *cub_data, int error);
//

//	list_tools.c
int		path_to_list(t_cub_data *cub_data, char *path, t_node *list_head);
t_node	*list_pop(t_node **to_pop_p);
void	list_add(t_node *list, t_node *to_add);
void	free_node(t_node *node);
void	free_list(t_node *list_head);
//

//	list_tools_extra.c
int		list_len(t_node *list); //not head, needs first elem
int		max_list_width(t_node *list);
void	remove_next_lines(t_node *list);
//

//	map_tools.c
int		is_map_data(char *line);
void	map_trim(t_node *map_head);
int		extract_map(t_cub_data *cub_data, t_node *list, t_node *map_head);
//

//	map_tools_extra.c
int		extract_p_orientation(t_cub_data *cub_data);
int		extract_p_position(t_cub_data *cub_data);
int		convert_map(t_cub_data *cub_data);
int		check_around(int x, int y, t_cub_data *cub_data);
int		verify_map(t_cub_data *cub_data);
//

//	predicates.c
int		ft_isspace(int c);
int		ft_isnum(int c);
int		is_orientation(int c);
int		is_whiteline(char *line);
int		is_wall_or_air(int target);
//

//	frees.c
void	free_map_i(t_cub_data *cub_data);
void	free_all(t_node *list_head, t_cub_data *cub_data);
void	free_char_arr(char **arr);
void	free_until(char **map_c, int i);
//

//	texture_rgb.c
int		process_identify(char *line);
int		process_texture(char *line, t_cub_data *cub_data);
int		colors_to_int(t_cub_data *cub_data, char **colors, int *colors_int);
int		process_rgb(char *line, t_cub_data *cub_data);
//

//	parser.c
int		parsing(t_cub_data *cub_data, char *path);
//

#endif
