/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:23:59 by akostian          #+#    #+#             */
/*   Updated: 2024/04/11 14:30:13 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	while (n-- > 0)
		*s_cpy++ = 0;
}

/* 
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int		i;
	char	testcase1[22] = "jshfisheiufhsieufhus";

	i = 0;
	ft_bzero(testcase1+3, 10);
	while (i < 22)
	{
		if (!testcase1[i])
			printf("\\0");
		else
			printf("%c", testcase1[i]);
		i++;
	}
	
}
 */