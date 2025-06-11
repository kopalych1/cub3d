/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:00:32 by akostian          #+#    #+#             */
/*   Updated: 2024/04/08 10:56:44 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", ft_isdigit('b'));
	printf("%d\n", ft_isdigit('6'));
	printf("%d\n", ft_isdigit('*'));
	printf("%d\n", ft_isdigit('0'));
} */