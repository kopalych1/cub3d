/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:02:13 by akostian          #+#    #+#             */
/*   Updated: 2024/04/12 14:01:23 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_word_count(char const *str, char c)
{
	int	new_word;
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
		{
			str++;
			new_word = 0;
		}
		while (*str && *str != c)
		{
			str++;
			new_word = 1;
		}
		if (*str || new_word)
			count++;
	}
	return (count);
}

int	get_next_word_len(char const *str, char c)
{
	int	word_len;

	word_len = 0;
	while (*str && *str != c)
	{
		word_len++;
		str++;
	}
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	const int	word_count = get_word_count(s, c);
	int			word_n;
	char		**ret_arr;

	ret_arr = malloc(sizeof(char *) * (word_count + 1));
	if (!ret_arr)
		return (NULL);
	word_n = 0;
	while (word_n < word_count)
	{
		while (*s && *s == c)
			s++;
		ret_arr[word_n++] = ft_substr(s, 0, get_next_word_len(s, c));
		while (*s && *s != c)
			s++;
	}
	ret_arr[word_n] = 0;
	return (ret_arr);
}
/* 
#include <stdio.h>

int	main(void)
{
	char	**arr;

	arr = ft_split("ysgef,mmmyuse,afsefse,iai,,,AXL", ',');
	printf("Words:\n");
	while (*arr)
	{
		printf("'%s'\n", *arr);
		arr++;
	}
	
} */