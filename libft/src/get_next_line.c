/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:03:45 by akostian          #+#    #+#             */
/*   Updated: 2024/07/22 15:09:04 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
#endif

char	*check_and_return(char **result)
{
	const size_t	result_len = ft_strlen(*result);
	size_t			i;
	char			*ret;
	char			*result_cpy;

	if (!result)
		return (NULL);
	result_cpy = *result;
	i = 0;
	while (i < result_len)
	{
		if (result_cpy[i] == '\n')
		{
			if (!result_cpy[i + 1])
				return (NULL);
			ret = ft_substr(result_cpy, 0, i + 1);
			*result = ft_substr(*result, i + 1, ft_strlen(&result_cpy[i + 1]));
			free(result_cpy);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

void	append_buffer(char **result, char (*buffer)[BUFFER_SIZE + 1])
{
	char	*old_result;

	old_result = *result;
	*result = ft_strjoin(*result, *buffer);
	free(old_result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*ret;
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	while (1)
	{
		ret = check_and_return(&result);
		if (ret)
			return (ret);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			ret = result;
			result = NULL;
			return (ret);
		}
		buffer[bytes_read] = '\0';
		append_buffer(&result, &buffer);
		if (!result)
			return (NULL);
	}
}
