/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 10:59:31 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/07/17 10:27:42 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room *new_room(void)
{
    t_room *room;

    if (!(room = malloc(sizeof(t_room) * 1)))
        return (NULL);
    room->room_name = NULL;
    room->pos_x = 0;
    room->pos_y = 0;
    room->links = NULL;
    room->visited = 0;
    room->prev_room = NULL;
    room->next = NULL;
    return (room);
}

t_link *new_link(void)
{
    t_link *link;

    if (!(link = malloc(sizeof(t_link) * 1)))
        return (NULL);
    link->room_name = NULL;
    link->next = NULL;
    return (link);
}

t_no_of_ants *new_ant(void)
{
    t_no_of_ants *ant;

    if (!(ant = malloc(sizeof(t_no_of_ants) * 1)))
        return (NULL);
    ant->move = NULL;
    ant->ant_no = 0;
    ant->arrived = 0;
    ant->next = NULL;
    return (ant);
}

t_lemin init_lemin(void)
{
    t_lemin lemin;

    lemin.ant_total = 0;
    lemin.start_room = NULL;
    lemin.end_room = NULL;
    lemin.rooms = NULL;
    lemin.path = NULL;
    lemin.ants = NULL;
    return (lemin);
}
    
int     main(void)
{
    t_lemin lemin;

    lemin = init_lemin();
    get_input(&lemin);
    if (links_found(&lemin))
    {
        calc_routes(&lemin);
        move_ants(&lemin);
    }
    else
        ft_putendl("ERROR");
    free_structs(&lemin);
    return (0);
}
