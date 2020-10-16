/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 18:23:19 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/06/30 14:29:25 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
/*calculate the path required to move the ants*/
void calc_routes(t_lemin *lemin)
{
    t_room *current_room;
    t_link *link;
    char *linked_room;

    current_room = find_room(lemin, lemin->end_room);
    linked_room = NULL;
    lemin->path = NULL;
    link = new_link();
    link->room_name = ft_strdup(lemin->end_room);
    lemin->path = add_link(lemin->path, link);
    while (ft_strcmp(linked_room, lemin->start_room) != 0)
    {
        if (linked_room)
            free(linked_room);
        linked_room = ft_strdup(current_room->prev_room);
        link = new_link();
        link->room_name = ft_strdup(linked_room);
        if (ft_strcmp(linked_room, lemin->start_room) != 0)
            lemin->path = add_link(lemin->path, link);
        else
            free_links(&link);
        current_room = find_room(lemin, linked_room);
    }
    free(linked_room);
}

t_link *connect_links(t_lemin *lemin, t_room *room, t_link *links)
{
    t_room *linked_room;
    t_link *link_item;
    t_link *linked;

    linked = room->links;
    while (linked)
    {
        linked_room = find_room(lemin, linked->room_name);
        if (!linked_room->visited && !list_of_links(links, linked_room->room_name))
        {
            link_item = new_link();
            link_item->room_name = ft_strdup(linked_room->room_name);
            linked_room->prev_room = ft_strdup(room->room_name);
            links = add_link_to_end(links, link_item);
        }
        linked = linked->next;
    }
    return (links);
}
/*Checks if the rooms have other rooms connected*/
int links_found(t_lemin *lemin)
{
    t_link *links;
    t_link *temp_link;
    t_room *current_room;

    links = new_link();
    links->room_name = ft_strdup(lemin->start_room);
    while (links)
    {
        current_room = find_room(lemin, links->room_name);
        temp_link = links;
        links = links->next;
        free(temp_link->room_name);
        free(temp_link);
        if (ft_strcmp(current_room->room_name, lemin->end_room) == 0)
        {
            free_links(&links);
            return (1);
        }
        if (!current_room->visited)
            current_room->visited = 1;
        links = connect_links(lemin, current_room, links);
    }
    free(links);
    return (0);
}