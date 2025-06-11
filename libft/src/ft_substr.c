/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:03:13 by akostian          #+#    #+#             */
/*   Updated: 2024/04/17 12:43:22 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	char			*ret;
	size_t			i;

	if (start + len <= s_len)
		ret = malloc(sizeof(char) * (len + 1));
	else
	{
		if (start >= s_len)
			return (ft_strdup(""));
		ret = malloc(sizeof(char) * (s_len - start + 1));
	}
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
/* 
#include <stdio.h>

int	main(void)
{
	char	str1[22] = "0123456789";

	printf("'%s'\n", ft_substr(str1, 3, 5));
	printf("'%s'\n", ft_substr(str1, 2, 10));
	printf("'%s'\n", ft_substr(str1, 12, 7));
} */