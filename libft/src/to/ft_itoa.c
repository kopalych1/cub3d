/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:50:29 by akostian          #+#    #+#             */
/*   Updated: 2024/04/12 17:32:18 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_int_len(int n)
{
	int	length;

	length = (n == 0);
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	const int	nb_length = get_int_len(n);
	int			ten_power;
	char		*ret;
	int			i;

	ret = malloc(sizeof(char) * (nb_length + (n < 0) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (n < 0)
		ret[i++] = '-';
	ten_power = ft_power(10, nb_length - 1);
	while (ten_power > 0)
	{
		ret[i++] = ft_abs((n / ten_power) % 10) + '0';
		ten_power /= 10;
	}
	ret[i] = '\0';
	return (ret);
}

/* 
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
} */