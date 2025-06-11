/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:55:25 by akostian          #+#    #+#             */
/*   Updated: 2024/04/17 13:46:10 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putstr_fd("2147483648", fd);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
/* 
int	main(void)
{
	int	fd;

	fd = open("test", O_WRONLY);
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(47483648, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-123123, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-5, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-10, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(10, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(100, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-100, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-123, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(123, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(9, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
} */
