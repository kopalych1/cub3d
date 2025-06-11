/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:38:26 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/10 13:57:14 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		||c == '\v' || c == '\f' || c == '\r');
}

int	ft_isnum(int c)
{
	return (c >= 48 && c <= 57);
}

int	is_orientation(int c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	is_whiteline(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

int	is_wall_or_air(int target)
{
	if (target == 0 || target == 1)
		return (1);
	return (0);
}
