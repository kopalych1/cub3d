/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putll_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:18:39 by akostian          #+#    #+#             */
/*   Updated: 2024/07/22 15:48:30 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putll_nbr(long long nbr)
{
	int	length;

	length = 1 + (nbr < 0);
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == LLONG_MIN)
		{
			ft_putstr("9223372036854775807");
			return (19);
		}
		nbr = -nbr;
	}
	if (nbr >= 10)
		length += ft_putll_nbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
	return (length);
}
