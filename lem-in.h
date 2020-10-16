/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 10:59:14 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/07/17 11:02:45 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define MAX_INT    32767
# define BUFF_SIZE  32

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "./libft/libft.h"

typedef struct              s_link
{
    char                    *room_name;
    struct s_link           *next;
}                           t_link;

typedef struct              s_room
{
    char                    *room_name;
    int                     pos_x;
    int                     pos_y;
    int                     visited;
    char                    *prev_room;
    t_link                  *links;
    struct s_room           *next;
}                           t_room;

typedef struct              s_no_of_ants
{
    int                     ant_no;
    int                     begin;
    int                     arrived;
    t_link                  *move;
    struct s_no_of_ants     *next;
}                           t_no_of_ants;

typedef struct              s_lemin
{
    int                     ant_total;
    char                    *start_room;
    char                    *end_room;
    t_room                  *rooms;
    t_link                  *path;
    t_no_of_ants            *ants;
}                           t_lemin;

/*
** Read input and get information
*/
void    get_input();
void    get_ants(char *input, t_lemin *lemin);
void    start_end(t_lemin *lemin, int start, int end);
int     get_next_line(const int fd, char **line);
int     get_room(char *line, t_lemin *lemin, int start, int end);
void    get_ants(char *input, t_lemin *lemin);
int     get_link(char *line, t_lemin *lemin);

/*
** Free all structs
*/
int     free_exit(t_lemin *lemin);
void    free_structs(t_lemin *lemin);
void    free_links(t_link **links);
void    free_ants(t_no_of_ants **ants);
void    free_input(char ***input);

/*
** Error handling and validation
*/
int     ft_isnum(char *str);
int     room_info_error(t_lemin *lemin, char ***input);
int     room_found(t_lemin *lemin, char *room);
void    add_room_to_end(t_lemin *lemin, t_room *room);
t_room  *find_room(t_lemin *lemin, char *room_name);

/*
** Initializing structs
*/
t_lemin         init_lemin(void);
t_room          *new_room(void);
t_link          *new_link(void);
t_no_of_ants    *new_ant(void);

/*
** Adding links to rooms
*/
void    save_links(t_lemin *lemin, char *str1, char *str2);
int     list_of_links(t_link *list, char *room_name);
t_link  *add_link_to_end(t_link *list, t_link *link_item);
t_link  *add_link(t_link *list, t_link *link_item);

/*
** Calculate and find routes
*/
int     links_found(t_lemin *lemin);
t_link  *connect_links(t_lemin *lemin, t_room *room, t_link *links);
void    calc_routes(t_lemin *lemin);

/*
** Move the ants
*/
void            move_ants(t_lemin *lemin);
int             num_of_rooms(t_link *link);
t_no_of_ants    *create_ants(t_lemin *lemin);
void            move(t_no_of_ants *ants);
t_no_of_ants    *ant_found(t_no_of_ants *ants);

#endif
