/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:14:16 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/07/12 18:19:29 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int num_of_rooms(t_link *link)
{
    int count;

    count = 0;
    while (link)
    {
        link = link->next;
        count++;
    }
    return (count);
}

t_no_of_ants *create_ants(t_lemin *lemin)
{
    t_no_of_ants *ant_list;
    t_no_of_ants *ant;
    int ant_number;

    ant_list = NULL;
    ant_number = lemin->ant_total;
    while (ant_number > 0)
    {
        ant = new_ant();
        ant->ant_no = ant_number;
        ant->move = lemin->path;
        ant->begin = 0;
        ant->arrived = 0;
        ant->next = ant_list;
        ant_list = ant;
        ant_number--;
    }
    return (ant_list);
}

void move(t_no_of_ants *ants)
{
    while (ants)
    {
        if (ants->begin)
        {
            if (ants->arrived)
            {
                ants = ants->next;
                continue;
            }
            ft_putchar('L');
            ft_putnbr(ants->ant_no);
            ft_putchar('-');
            ft_putstr(ants->move->room_name);
            ants->move = ants->move->next;
            if (ants->move == NULL)
                ants->arrived = 1;
            ft_putchar(' ');
        }
        ants = ants->next;
    }
}

t_no_of_ants *ant_found(t_no_of_ants *ants)
{
    while (ants->next && ants->next->begin)
        ants = ants->next;
    return (ants);
}

void move_ants(t_lemin *lemin)
{
    int num_of_moves;
    t_no_of_ants *ants;

    num_of_moves = num_of_rooms(lemin->path) - 1 + lemin->ant_total;
    lemin->ants = create_ants(lemin);
    lemin->ants->begin = 1;
    ft_putchar('\n');
    while (num_of_moves > 0)
    {
        move(lemin->ants);
        ants = ant_found(lemin->ants);
        if (ants->next)
            ants->next->begin = 1;
        ft_putchar('\n');      
        num_of_moves--;
    }
}