/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:40:40 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/09/23 02:19:17 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int  ft_read(int const fd, char **str)
{
    char    *buff;
    char    *temp;
    int     size;

    if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
        return (-1);
    size = read(fd, buff, BUFF_SIZE);
    if (size > 0)
    {
        buff[size] = '\0';
        temp = ft_strjoin(*str, buff);
        free(*str);
        *str = temp;
    }
    free(buff);
    return (size);
}

int     get_next_line(const int fd, char **line)
{
    static char *str = NULL;
    char        *next_line;
    int         size;

    if ((!str && (str = (char *)malloc(sizeof(*str))) == NULL) ||
            !line || fd < 0 || BUFF_SIZE < 0)
        return (-1);
    next_line = ft_strchr(str, '\n');
    while (next_line == '\0')
    {
        size = ft_read(fd, &str);
        if (size == 0)
        {
            if (ft_strlen(str) == 0)
                return (0);
            str = ft_strjoin(str, "\n");
        }
        if (size < 0)
            return (-1);
        else
            next_line = ft_strchr(str, '\n');
    }
    *line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(next_line));
    str = ft_strdup(next_line + 1);
    return (1);
}
