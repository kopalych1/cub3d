/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:41:50 by akostian          #+#    #+#             */
/*   Updated: 2024/05/07 16:46:55 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	joined_len = ft_strlen(s1) + ft_strlen(s2);
	char			*ret;
	size_t			i;

	ret = malloc(sizeof(char) * (joined_len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			ret[i++] = *s1++;
	if (s2)
		while (*s2)
			ret[i++] = *s2++;
	ret[i] = '\0';
	return (ret);
}

/* #include <stdio.h>

int	main(void)
{
	char	str1[22] = "";
	char	str2[22] = "123";
	char	*str3;

	str3 = ft_strjoin(str1, str2);
	printf("%s\n", str3);
} */