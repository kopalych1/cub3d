/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:41:47 by akostian          #+#    #+#             */
/*   Updated: 2024/04/16 15:59:03 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occ;

	last_occ = NULL;
	while (1)
	{
		if (*s == c)
			last_occ = (char *)s;
		if (!*s)
			break ;
		s++;
	}
	return (last_occ);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	testcase1[22] = "jshfisKeiufhsieufhus";

	printf("'%s'\n", ft_strrchr(testcase1, '\0'));
	printf("'%s'\n", strrchr(testcase1, '\0'));
}
 */