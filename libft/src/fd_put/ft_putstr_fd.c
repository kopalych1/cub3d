/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:32:34 by akostian          #+#    #+#             */
/*   Updated: 2024/04/14 13:55:34 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/* 
int	main(void)
{
	int	fd;

	fd = open("test", O_WRONLY);
	ft_putstr_fd("iasjfoeijfosie", fd);
	close(fd);
} */