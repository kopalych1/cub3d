/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:30:04 by akostian          #+#    #+#             */
/*   Updated: 2024/04/14 14:04:22 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const size_t	s_len = ft_strlen(s);
	char			*ret;
	unsigned int	i;

	ret = malloc(sizeof(char) * (s_len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/* 
#include <stdio.h>

char	next_char(unsigned int index, char c)
{
	index++;
	return (c + 1);
}

int	main(void)
{
	printf("%s\n", ft_strmapi("abc", next_char));
} */