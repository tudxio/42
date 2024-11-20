/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:22:52 by lobenard          #+#    #+#             */
/*   Updated: 2024/11/18 17:28:30 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;

	temp = NULL;
	while (*str)
	{
		if (*str == (char)c)
			temp = (char *)str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (temp);
}
