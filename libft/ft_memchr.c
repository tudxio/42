/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:06:08 by lobenard          #+#    #+#             */
/*   Updated: 2024/11/18 17:28:22 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	const unsigned char	*ptr = (const unsigned char *)s;
	unsigned char		uc;
	size_t				i;

	uc = (unsigned char)c;
	i = 0;
	while (i < size)
	{
		if (ptr[i] == uc)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
