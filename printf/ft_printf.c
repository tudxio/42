/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:16:58 by lobenard          #+#    #+#             */
/*   Updated: 2024/12/12 17:14:18 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_format(va_list args, const char format)
{
	int	print;

	print = 0;
	if (format == 'c')
		print += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print += ft_printnbr(va_arg(args, int));
	else if (format == '%')
		print += ft_printchar('%');
	else
		print += ft_printchar(format);
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
			print += ft_printchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (print);
}
