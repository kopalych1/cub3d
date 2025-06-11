/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:02:25 by akostian          #+#    #+#             */
/*   Updated: 2024/07/22 15:47:42 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	route(char flag, va_list args, int *length)
{
	if (flag == 'd' || flag == 'i')
		*length += ft_putll_nbr((int)va_arg(args, int));
	else if (flag == 'u')
		*length += ft_putll_nbr((unsigned int)va_arg(args, unsigned int));
	else if (flag == '%')
		*length += ft_putchar('%');
	else if (flag == 'c')
		*length += ft_putchar((unsigned char)va_arg(args, int));
	else if (flag == 'x' || flag == 'X')
		*length += ft_puthex(va_arg(args, unsigned int), (flag == 'X'));
	else if (flag == 'p')
		*length += ft_putptr(va_arg(args, void *));
	else if (flag == 's')
		*length += ft_putstr(va_arg(args, char *));
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				length;

	length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_strchr("cspdiuxX%", *str++))
				route(*str++, args, &length);
		}
		else
		{
			ft_putchar(*str++);
			length++;
		}
	}
	va_end(args);
	return (length);
}
