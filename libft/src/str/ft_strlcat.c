/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:12:50 by akostian          #+#    #+#             */
/*   Updated: 2024/04/12 12:51:36 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(
			char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dst_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	if (dstsize <= dst_size)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] && dst_size + 1 < dstsize)
		dst[dst_size++] = src[i++];
	dst[dst_size] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}

/* #include <stdio.h>
int	main(void)
{
	char	testcase1[40] = "jshfisKeiuaaaaaaaaaaa";
	char	testcase2[22] = "jshfisKeiu";

	printf("%d\n", ft_strlcat(testcase1, testcase2, 20));
	printf("%s\n", testcase1);
	printf("%s\n", testcase2);
}
 */