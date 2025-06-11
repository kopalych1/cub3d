/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:23:20 by akostian          #+#    #+#             */
/*   Updated: 2024/07/24 04:45:17 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long nbr, int is_upper)
{
	char	buffer[16];
	int		i;
	int		length;

	if (!nbr)
		return (ft_putchar('0'));
	length = 0;
	i = 0;
	while (nbr)
	{
		buffer[i++] = HEX[nbr % 16];
		nbr /= 16;
	}
	while (i-- > 0)
	{
		if (is_upper)
			ft_putchar(ft_toupper(buffer[i]));
		else
			ft_putchar(buffer[i]);
		length++;
	}
	return (length);
}
