/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:21:33 by jelmalem          #+#    #+#             */
/*   Updated: 2017/01/10 18:21:33 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/libftprintf.h"
# include "../libft/includes/get_next_line.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_room		t_room;
typedef struct s_voisin		t_voisin;
typedef struct s_parcouru	t_parcouru;
typedef struct s_seclist	t_seclist;

struct						s_seclist
{
	char					*line;
	t_seclist				*next;
};

struct						s_room
{
	char					*name;
	int						x;
	int						y;
	int						distance;
	int						use;
	int						id;
	t_room					*next;
	t_voisin				*next_voisin;
};

struct						s_voisin
{
	t_room					*room;
	t_voisin				*next;
};

struct						s_parcouru
{
	char					*name;
	int						*ant;
};

extern int					g_id;
extern int					g_ant_count;
extern int					g_case_count;
extern int					g_max_pass;
extern int					g_id_start;
extern int					g_id_end;
extern t_room				*g_room_list;

typedef struct				s_parsing
{
	int						fourmis;
	char					*start;
	char					*end;
	char					*tabroom[100000];
	char					*tabconnect[100000];
}							t_parsing;

t_room						*find_room_hashtag(t_room *room, int id);
void						room_push_front(t_room **room_head,
							t_room *room_to_copy);
t_room						*room_exist(t_room *room, char *name);
void						voisin_push_front(t_voisin **voisin, t_room *room);
t_voisin					*next_voisin(t_room *room);
void						room(char **tabroom);
void						way(char **tabconnect);
int							find_id(char **tabroom, char *name);
t_parcouru					*init_struct_parcours(t_room *room,
							int	g_ant_count);
void						dijkstra(t_room *room, int distance);
void						display_step(t_room *room, int number_ant,
							t_parcouru *parcouru, t_room *tmp3);
void						display_algo(t_room *room, t_room *destination,
							t_parcouru *parcouru, int g_ant_count);
int							ft_is_number(char *number);
int							ft_tabchr(char **tab1, char *c);
int							countstr(char *str, char c);
int							ft_fourmis(char	*line);
char						*ft_start_end(char *line);
int							ft_verifline(char *line);
int							parsing_ter(char *line, t_parsing *var,
							int i, t_seclist *list);
int							parsing_bis(char *line, t_parsing *var, int y);
void						ft_error(t_parsing *var, t_seclist *list);
t_seclist					*insertion(t_seclist *list, char *nvnombre);
void						printfile(t_seclist *list);

#endif
