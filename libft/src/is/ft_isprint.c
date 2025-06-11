/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:44:11 by akostian          #+#    #+#             */
/*   Updated: 2024/04/08 10:53:45 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= ' ' && c < 127);
}

/* 
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	i=-1;

	while (++i < 255)
	{
		if (isprint(i) != ft_isprint(i))
			if (!isprint(i))
			{
				printf("Error: \t");
				printf("i: %d\t%d\t%d\n", i,  isprint(i), ft_isprint(i));
			}
		// printf("i: %d\t%d\t%d\n", i,  isprint(i), ft_isprint(i));
	}
} */