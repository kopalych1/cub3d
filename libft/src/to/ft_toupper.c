/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:11:18 by akostian          #+#    #+#             */
/*   Updated: 2024/04/08 14:14:25 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	return (c - (32 * (c >= 'a' && c <= 'z')));
}
/* 
#include <stdio.h>
int	main(void)
{
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('b'));
	printf("%c\n", ft_toupper('6'));
	printf("%c\n", ft_toupper('*'));
	printf("%c\n", ft_toupper('&'));
} */