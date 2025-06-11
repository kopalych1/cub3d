/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:32:11 by akostian          #+#    #+#             */
/*   Updated: 2024/04/17 11:54:29 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (!*s1)
		return (ft_substr(s1, 0, 1));
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

/* #include <stdio.h>

int	main(void)
{
	printf("'%s'\n", ft_strtrim("AAAAAAAA", "A"));
	printf("'%s'\n", ft_strtrim("AAAAA.sssssaadawsssa.AAA", "A"));
	printf("'%s'\n", ft_strtrim("AAA,AadddsqwjsqweqwwwaaaAAABB;BBCCCCA", "ABC"));
} */