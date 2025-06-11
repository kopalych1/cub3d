/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:17:55 by akostian          #+#    #+#             */
/*   Updated: 2024/04/16 15:54:49 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (!*s)
			return (NULL);
		s++;
	}
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	testcase1[22] = "jshfisKeiufhsieufhus";

	printf("'%s'\n", ft_strchr(testcase1, '\0'));
	printf("'%s'\n", strchr(testcase1, '\0'));
}
 */