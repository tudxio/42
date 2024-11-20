/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:25:17 by lobenard          #+#    #+#             */
/*   Updated: 2024/11/20 17:51:31 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (start < len && is_in_set(s1[start], set))
		start++;
	end = len - 1;
	while (end > start && is_in_set(s1[end], set))
		end--;
	len = end - start + 1;
	trimmed = (char *)malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len);
	trimmed[len] = '\0';
	return (trimmed);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *original = "   Hello, world!   ";
    const char *set = " ";

    char *trimmed = ft_strtrim(original, set);

    if (trimmed == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Original: '%s'\n", original);
    printf("Trimmed: '%s'\n", trimmed);

    // Libérer la mémoire allouée
    free(trimmed);

    return 0;
}
