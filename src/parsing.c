/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:04:32 by jelmalem          #+#    #+#             */
/*   Updated: 2017/01/10 14:04:32 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int					g_id;
int					g_case_count;
int					g_max_pass;
int					g_id_start;
int					g_id_end;
t_room				*g_room_list;

t_parcouru			*init_struct_parcours(t_room *room, int g_ant_count)
{
	int				i;
	int				j;
	t_room			*tmp;
	t_parcouru		*parcouru;

	i = 0;
	parcouru = (t_parcouru*)malloc((g_case_count - 1) * sizeof(t_parcouru));
	while (i != g_case_count - 1)
	{
		j = 0;
		tmp = room;
		room = next_voisin(room)->room;
		parcouru[i].name = room->name;
		parcouru[i].ant = (int*)malloc((g_ant_count) * sizeof(int));
		while (j != g_ant_count)
		{
			parcouru[i].ant[j] = 0;
			j++;
		}
		i++;
	}
	return (parcouru);
}

void				run_algo(t_parsing *var, t_seclist *list, int x)
{
	t_room			*start;
	t_room			*end;
	t_parcouru		*parcouru;

	if (var->start == NULL || var->end == NULL)
	{
		ft_putstr("ERROR - START OU END\n");
		exit(0);
	}
	room(var->tabroom);
	way(var->tabconnect);
	start = find_room_hashtag(g_room_list, find_id(var->tabroom, var->start));
	end = find_room_hashtag(g_room_list, find_id(var->tabroom, var->end));
	parcouru = init_struct_parcours(start, var->fourmis);
	end->distance = 0;
	dijkstra(end, 0);
	if (x == 1)
	{
		printfile(list);
		ft_printf("\n");
	}
	display_algo(start, end, parcouru, var->fourmis);
}

void				ft_error(t_parsing *var, t_seclist *list)
{
	if (var->start != NULL && var->end != NULL)
	{
		if (var->tabconnect[0] != NULL && var->tabconnect[1] != NULL)
		{
			ft_putstr("ERROR - On va tenter de lancer l'algo !\n");
			run_algo(var, list, 0);
			exit(0);
		}
	}
	else
	{
		ft_putstr("ERROR - Pas assez d'infos pour lancer l'algo\n");
		exit(0);
	}
}

void				parsing(int fichier)
{
	char			*line;
	int				i;
	int				y;
	t_parsing		var;
	t_seclist	*list;

	var.start = NULL;
	var.end = NULL;
	var.fourmis = 0;
	i = 0;
	y = 0;
	list = NULL;
	while (get_next_line(fichier, &line) == 1)
	{
		if (line == NULL)
			run_algo(&var, list, 0);
		if (ft_verifline(line) == 1 && var.fourmis != 0)
			ft_error(&var, list);
		list = insertion(list, line);
		y = parsing_bis(line, &var, y);
		i = parsing_ter(line, &var, i, list);
		ft_strdel(&line);
	}
	var.tabconnect[i] = NULL;
	run_algo(&var, list, 1);
}

int					main(int argc, char *argv[])
{
	int	fichier;

	if (argc == 1)
		parsing(0);
	else if (argc >= 2)
	{
		ft_putstr("ERROR - Arg\n");
		exit(0);
	}
	fichier = 0;
}
