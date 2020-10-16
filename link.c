/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 13:36:52 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/07/04 22:29:37 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void save_links(t_lemin *lemin, char *str1, char *str2)
{
    t_link *link;
    t_room *room;

    room = find_room(lemin, str1);
    if (list_of_links(room->links, str2))
        free_exit(lemin);
    link = new_link();
    link->room_name = ft_strdup(str2);
    room->links = add_link_to_end(room->links, link);
}

int list_of_links(t_link *list, char *room_name)
{
    while (list)
    {
        if (ft_strcmp(list->room_name, room_name) == 0)
            return (1);
        list = list->next;
    }
    return (0);
}

t_link *add_link_to_end(t_link *list, t_link *link_item)
{
    t_link *temp_list;

    if (list == NULL)
    {
        list = link_item;
        return (list);
    }
    temp_list = list;
    while (temp_list->next)
        temp_list = temp_list->next;
    temp_list->next = link_item;
    link_item->next = NULL;
    return (list);
}

t_link *add_link(t_link *list, t_link *link_item)
{
    link_item->next = list;
    list = link_item;
    return (list);
}