/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:16:58 by lobenard          #+#    #+#             */
/*   Updated: 2024/12/19 17:26:36 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_format(va_list args, const char format)
{
	int	print;

	print = 0;
	if (format == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print += ft_putchar('%');
	else
		print += ft_putchar(format);
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += ft_format(args, str[i + 1]);
			i += 2;
		}
		else
		{
			print += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (print);
}
