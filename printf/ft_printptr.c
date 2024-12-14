/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:51:11 by lobenard          #+#    #+#             */
/*   Updated: 2024/12/12 17:22:58 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// Fonction pour convertir un pointeur en une chaîne hexadécimale
void	ft_ptr_to_hex(unsigned long long ptr, char *buffer, int *len)
{
	int					i;
	int					rem;
	unsigned long long	temp;

	temp = ptr;
	i = 18;
	buffer[i--] = '\0';
	while (temp > 0)
	{
		rem = temp % 16;
		if (rem < 10)
			buffer[i--] = rem + '0';
		else
			buffer[i--] = rem - 10 + 'a';
		temp = temp / 16;
		(*len)++;
	}
}

// Fonction principale pour imprimer un pointeur
int	ft_printptr(unsigned long long ptr)
{
	char	buffer[19];
	int		len;
	int		i;

	len = 0;
	if (!ptr)
		return (ft_printstr("(nil)"));

	buffer[0] = '0';
	buffer[1] = 'x';
	len = 2;
	ft_ptr_to_hex(ptr, buffer, &len);
	i = 18 - (len - 2);
	write(1, buffer + i, len);
	return (len);
}
