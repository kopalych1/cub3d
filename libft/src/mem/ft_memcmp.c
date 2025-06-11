/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:15:23 by akostian          #+#    #+#             */
/*   Updated: 2024/04/11 14:38:02 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*s1_cpy != *s2_cpy)
			return (*s1_cpy - *s2_cpy);
		s1_cpy++;
		s2_cpy++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[77] = "jshfisheiufhsieufh";
	char	str2[77] = "jshfisheiufhsieufh";

	printf("%d\n", ft_memcmp(str1, str2, 60));
	printf("%d\n", memcmp(str1, str2, 60));
} */