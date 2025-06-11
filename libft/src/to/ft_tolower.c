/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:14:34 by akostian          #+#    #+#             */
/*   Updated: 2024/04/08 14:15:48 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	return (c + (32 * (c >= 'A' && c <= 'Z')));
}
/* 
#include <stdio.h>
int	main(void)
{
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('B'));
	printf("%c\n", ft_tolower('H'));
	printf("%c\n", ft_tolower('*'));
	printf("%c\n", ft_tolower('&'));
} */