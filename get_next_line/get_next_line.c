/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:15:05 by lobenard          #+#    #+#             */
/*   Updated: 2025/01/28 17:13:21 by lobenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    if (!buffer)
        buffer = ft_calloc(1, 1);
    buffer = read_fd(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_line(buffer);
    buffer = ft_next(buffer);
    if (buffer && !*buffer)
    {
        free(buffer);
        buffer = NULL;
    }
    return (line);
}

char    *read_fd(int fd, char *buf)
{
    char    *buffer;
    int     byte_read;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
    {
        free(buf);
        return (NULL);
    }
    byte_read = 1;
    while (byte_read > 0)
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read == -1)
        {
            free(buffer);
            free(buf);
            return (NULL);
        }
        buffer[byte_read] = 0;
        buf = ft_free(buf, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (buf);
}

char    *ft_free(char *buffer, char *buf)
{
    char    *temp;

    temp = ft_strjoin(buffer, buf);
    free(buffer);
    return (temp);
}

char    *ft_line(char *buffer)
{
    char    *line;
    int     i;

    if (!buffer || !buffer[0])
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] && buffer[i] == '\n')
        line[i++] = '\n';
    return (line);
}

char    *ft_next(char *buffer)
{
    int     i;
    int     j;
    char    *line;

    if (!buffer)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
    if (!line)
    {
        free(buffer);
        return (NULL);
    }
    i++;
    j = 0;
    while (buffer[i])
        line[j++] = buffer[i++];
    free(buffer);
    return (line);
}
