/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:49 by lobenard          #+#    #+#             */
/*   Updated: 2024/11/18 17:28:24 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	long	i;

	if (dest < src)
	{
		i = 0;
		while ((size_t)i < size)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dest);
	}
	else
	{
		i = size - 1;
		while (i >= 0)
		{
			*(unsigned char *)(dest - i) = *(unsigned char *)(src - i);
			i--;
		}
		return (dest);
	}
}
