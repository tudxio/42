/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:56:02 by lobenard          #+#    #+#             */
/*   Updated: 2024/12/19 17:34:15 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_printf.h>
#include <libft.h>

int	ft_puthex(unsigned int n, int maj)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16, maj);
		n = n % 16;
	}
	if (n < 10)
		len += ft_putchar(n + '0');
	else
	{
		if (maj == 'X')
			len += ft_putchar(n - 10 + 'A');
		else
			len += ft_putchar(n - 10 + 'a');
	}
	return (len);
}
