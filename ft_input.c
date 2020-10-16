/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 16:28:00 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/07/13 22:17:36 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void start_end(t_lemin *lemin, int start, int end)
{
    char *line;

    get_next_line(0, &line);
    if (ft_strlen(line) == 0 || (start && lemin->start_room) || (end && lemin->end_room))
        free_exit(lemin);
    ft_putendl(line);
    if (line[0] != '#')
        get_room(line, lemin, start, end);
    else
        start_end(lemin, start, end);
    free(line);
}

int read_input(char *input, t_lemin *lemin)
{
    int result;

    result = 1;
    if (input[0] == '#' && input[1] == '#')
    {
        if (ft_strcmp(&input[2], "start") == 0)
            start_end(lemin, 1, 0);
        else if (ft_strcmp(&input[2], "end") == 0)
            start_end(lemin, 0, 1);
    }
    else if (!ft_strchr(input, '-'))
        result = get_room(input, lemin, 0, 0);
    else if (ft_strchr(input, '-'))
        result = get_link(input, lemin);
    return (result);
}

void get_input(t_lemin *lemin)
{
    char *line;

    if (get_next_line(0, &line) == 0)
        free_exit(lemin);
    get_ants(line, lemin);
    free(line);
    while (get_next_line(0, &line) > 0 && ft_strlen(line) > 0)
    {
        ft_putendl(line);
        if (!(line[0] == '#' && line[1] != '#'))
        {
            if (!read_input(line, lemin))
            {
                free(line);
                return ;
            }
        }
        free(line);
        line = NULL;
    }
    if (line)
        free(line);
    if (!lemin->start_room || !lemin->end_room || !lemin->rooms || !lemin->rooms->links)
        free_exit(lemin);
}
