/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:31:40 by lobenard          #+#    #+#             */
/*   Updated: 2024/11/26 18:26:11 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	needle_len = ft_strlen(needle);
	i = 0;
	j = 0;
	if (len == 0)
		return (NULL);
	if (needle_len == 0)
		return ((char *)haystack);
	while (haystack[i] && i <= len - needle_len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
