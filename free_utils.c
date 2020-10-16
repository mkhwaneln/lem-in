/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 18:01:28 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/06/28 14:30:44 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void free_ants(t_no_of_ants **ants)
{
    t_no_of_ants *temp;

    while (*ants)
    {
        temp = *ants;
        *ants = (*ants)->next;
        free(temp);
    }
    free(*ants);
}

void free_links(t_link **links)
{
    t_link *temp_link;

    while (*links)
    {
        temp_link = *links;
        *links = (*links)->next;
        free(temp_link->room_name);
        free(temp_link);
    }
    free(*links);
}

void free_structs(t_lemin *lemin)
{
    t_room *temp_room;

    free(lemin->start_room);
    free(lemin->end_room);
    while (lemin->rooms)
    {
        temp_room = lemin->rooms;
        free_links(&temp_room->links);
        lemin->rooms = lemin->rooms->next;
        free(temp_room->room_name);
        free(temp_room->prev_room);
        free(temp_room);
    }
    free_links(&lemin->path);
    free_ants(&lemin->ants);
    free(lemin->rooms);
}

int    free_exit(t_lemin *lemin)
{
    if (!lemin->ant_total || !lemin->start_room || !lemin->end_room
    || !lemin->rooms|| !lemin->rooms->links)
    {
        if (lemin)
            free_structs(lemin);
        ft_putendl("ERROR");
        exit(0);
    }
    else
        return (0);
}

void free_input(char ***input)
{
    int in;

    in = 0;
    while ((*input)[in])
    {
        free((*input)[in]);
        in++;
    }
    free(*input);
}