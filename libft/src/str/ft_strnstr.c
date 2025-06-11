/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:25:47 by akostian          #+#    #+#             */
/*   Updated: 2024/04/17 13:35:48 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] && needle[j])
			&& (haystack[i + j] == needle[j])
			&& (i + j < len))
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
/* 
#include <stdio.h>
#include <string.h>

void	test_ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (strnstr(haystack, needle, len) != ft_strnstr(haystack, needle, len))
		printf("NOT okey: \t'%s', '%s', %zu\n", haystack, needle, len);
	else
		printf("\n");
}

int	main(void)
{
	//ft_strnstr(NULL, "asdv", 13);
	//strnstr(NULL, "asdv", 13);
	int i = 1;
	
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "world", 12);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "world", 5);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "hello", 12);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "hello", 4);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "hello", 3);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "o", 12);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "o", 4);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "", 12);
	printf("%d: ", i++);
	test_ft_strnstr("", "hello", 12);
	printf("%d: ", i++);
	test_ft_strnstr("hello\0world", "world", 12);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "world", 0);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "hello", 0);
	printf("%d: ", i++);
	test_ft_strnstr("hello world", "o", 0); */

	/* printf("%d: ", i++);
	test_ft_strnstr("", "", 0);
	printf("%d: ", i++);
	test_ft_strnstr("", "hello", 0);
	printf("%d: ", i++);
	test_ft_strnstr("hello", "", 0);

	//SEGFAULT tests:

	printf("Test 1:\n");
	printf("strnstr()\n");
	// strnstr(NULL, "hello", 5);
	printf("ft_strnstr()\n");
	// ft_strnstr(NULL, "hello", 5);

	printf("Test 2:\n");
	printf("strnstr()\n");
	// strnstr("hello", NULL, 5);
	printf("ft_strnstr()\n");
	// ft_strnstr("hello", NULL, 5);

	printf("Test 3:\n");
	printf("strnstr()\n");
	// strnstr(NULL, NULL, 0);
	printf("ft_strnstr()\n");
	// ft_strnstr(NULL, NULL, 0);
}
 */