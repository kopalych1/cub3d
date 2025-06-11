/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:29:16 by akostian          #+#    #+#             */
/*   Updated: 2024/04/11 15:28:17 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cpy;

	b_cpy = (unsigned char *)b;
	while (len-- > 0)
		*b_cpy++ = (unsigned char)c;
	return (b);
}

/* 
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	testcase1[22] = "jshfisheiufhsieufhus";

	ft_memset(testcase1, 123, 10);
	printf("%s\n", testcase1);
	memset(testcase1+3, 76, 5);
	printf("%s\n", testcase1);
	ft_memset(testcase1, 78, 4);
	printf("%s\n", testcase1);
}
 */