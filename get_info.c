/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 16:28:00 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/06/21 10:27:53 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int get_room(char *line, t_lemin *lemin, int start, int end)
{
    char **input;
    t_room *room;

    input = ft_strsplit(line, ' ');
    if (room_info_error(lemin, &input))
        return (0);
    room = new_room();
    room->room_name = ft_strdup(input[0]);
    room->pos_x = ft_atoi(input[1]);
    room->pos_y = ft_atoi(input[2]);
    if (start && !lemin->start_room)
        lemin->start_room = ft_strdup(input[0]);
    if (end && !lemin->end_room)
        lemin->end_room = ft_strdup(input[0]);
    if (!ft_isnum(input[1]) || !ft_isnum(input[2]) || ft_atoi(input[1]) < 0
    || ft_atoi(input[2]) < 0)
    {
        free_input(&input);
        free(room->room_name);
        free(room);
        return (0);
    }
    add_room_to_end(lemin, room);
    free_input(&input);
    return (1);
}

void get_ants(char *input, t_lemin *lemin)
{
    int no_of_ants;

    if (input == 0)
        free_exit(lemin);
    if (input[0] != '#')
    {
        if (!ft_isnum(input))
            free_exit(lemin);
        ft_putendl(input);
        no_of_ants = ft_atoi(input);
        if (no_of_ants <= 0 || no_of_ants > MAX_INT)
            free_exit(lemin);
        lemin->ant_total = no_of_ants;
    }
    else if (get_next_line(0, &input) > 0)
    {
        get_ants(input, lemin);
        free(input);
    }
}

int get_link(char *line, t_lemin *lemin)
{
    char **input;

    input = ft_strsplit(line, '-');
    if (!input[0] || !input[1] || !room_found(lemin, input[0]) || !room_found(lemin, input[1]))
    {
        if (!free_exit(lemin))
            return (0);
    }
    save_links(lemin, input[0], input[1]);
    save_links(lemin, input[1], input[0]);
    free_input(&input);
    return (1);
}