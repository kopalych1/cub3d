/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:05:15 by akostian          #+#    #+#             */
/*   Updated: 2024/07/22 15:53:11 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	const int	length = ft_strlen(s);

	if (!s)
		return (ft_putstr("(null)"));
	write(1, s, ft_strlen(s));
	return (length);
}
