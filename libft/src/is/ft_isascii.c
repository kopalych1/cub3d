/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:23:22 by akostian          #+#    #+#             */
/*   Updated: 2024/04/08 10:41:16 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	// int	i=-1;

	// while (++i < 255)
	// {
	// 	if (isascii(i) != ft_isascii(i))
	// 		printf("i: %d\t%d\t%d\n", i,  isascii(i), ft_isascii(i));
	// }
	printf("%d\t%d\n", ft_isascii('a'), isascii('a'));
	printf("%d\t%d\n", ft_isascii('b'), isascii('b'));
	printf("%d\t%d\n", ft_isascii('6'), isascii('6'));
	printf("%d\t%d\n", ft_isascii('*'), isascii('*'));
	printf("%d\t%d\n", ft_isascii(223), isascii(223));
} */