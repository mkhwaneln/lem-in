/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:00:32 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/06/22 22:11:59 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int ft_isnum(char *str)
{
    int in;

    in = 0;
    while (str[in] != '\0')
    {
        if (!ft_isdigit(str[in]))
            return (0);
        in++;
    }
    return (1);
}

int room_found(t_lemin *lemin, char *room)
{
    t_room *temp_room;

    if (lemin->rooms == NULL)
        return (0);
    temp_room = lemin->rooms;
    while (temp_room)
    {
        if (ft_strcmp(temp_room->room_name, room) == 0)
            return (1);
        temp_room = temp_room->next;
    }
    return (0);
}

int room_info_error(t_lemin *lemin, char ***input)
{
    if ((lemin->rooms && lemin->rooms->links) || !(*input)[0] || !(*input)[1] || !(*input)[2] || (*input)[3] != NULL || (*input)[0][0] == 'L' || room_found(lemin, (*input)[0]))
    {
        if (free_exit(lemin) == 0)
        {
            free_input(input);
            return (1);
        }
    }
    return (0);
}

void add_room_to_end(t_lemin *lemin, t_room *room)
{
    t_room *temp_room;

    if (lemin->rooms == NULL)
    {
        lemin->rooms = room;
        return ;
    }
    temp_room = lemin->rooms;
    while (temp_room->next != NULL)
        temp_room = temp_room->next;
    temp_room->next = room;
    room->next = NULL;
}

t_room *find_room(t_lemin *lemin, char *room_name)
{
    t_room *temp_room;

    temp_room = lemin->rooms;
    while (temp_room)
    {
        if (ft_strcmp(temp_room->room_name, room_name) == 0)
            return (temp_room);
        temp_room = temp_room->next;
    }
    return (NULL);
}