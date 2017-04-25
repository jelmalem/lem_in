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

t_parcouru	*init_struct_parcours(t_room *room, int	g_ant_count)
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

int	ft_is_number(char *number)
{
	int i;

	i = 0;
	while (i < ft_strlen(number))
	{
		if (ft_isdigit(number[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void test(t_parsing *var)
{
	t_room			*start;
	t_room			*end;
	t_parcouru		*parcouru;

	room(var->tabroom);
	way(var->tabconnect);
	printf("[ID START%d]\n", find_id(var->tabroom, var->start));
	printf("[ID END%d]\n", find_id(var->tabroom, var->end));
	start = find_room_hashtag(g_room_list, find_id(var->tabroom, var->start));
	end = find_room_hashtag(g_room_list, find_id(var->tabroom, var->end));
	parcouru = init_struct_parcours(start, var->fourmis);
	end->distance = 0;
	dijkstra(end, 0);
	display_algo(start, end, parcouru, var->fourmis);
}

static void	ft_error(t_parsing	*var)
{
	if (var->start != NULL && var->end != NULL)
	{	
		if (var->tabconnect[0] != NULL && var->tabconnect[1] != NULL)
		{
			printf("[Start %s]\n",var->start);
			printf("[End %s]\n",var->end);
			ft_putstr("On peut quand même lancer l'algo !\n");
			test(var);
			exit(0);
		}
	}
	else
	{
		ft_putstr("ERROR 1 - On ne peut pas lancer l'algo\n");
		exit(0);
	}
}

int			countstr(char *str, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int ft_fourmis(char *line)
{
	int fourmis;
	int i;

	i = 0;
	if (ft_strlen(line) == 0)
	{
		ft_putstr("ERROR FOURMIS\n");
		exit(0);
	}
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1)
			fourmis = ft_atoi(line);
		if (fourmis == 0)
		{
			ft_putstr("Il n'y a pas de fourmis EXIT !\n");
			exit(0);
		}
		else if (ft_isdigit(line[i]) != 1)
		{
			ft_putstr("ERROR FOURMIS\n");
			exit(0);
		}
		i++;
	}
	printf("[Fourmis %d]\n",fourmis);
	return(fourmis);
}


char *ft_start_end(char *line)
{
	char *val;
	char **tab;
	tab = ft_strsplit(line, ' ');
	if (tab[1] != NULL && ft_is_number(tab[1]) != 0 && ft_is_number(tab[2]) != 0)
	{
		val = tab[0];
		free(tab);
	}
	else
	{
		free(tab);
		ft_putstr("ERROR\n");
		exit(0);
	}
	return(val);
}

int ft_tabchr(char **tab1, char *c)
{
	int x;
	int count;

	count = 0;
	x = 0;
	while (tab1[x])
	{	
		if (ft_strcmp(tab1[x], c) == 0)
			count++;
		x++;
	}
	// printf("[Count %d]\n",count);
	return (count);
}

// void test(t_parsing *var)
// {
// 	t_room			*start;
// 	t_room			*end;
// 	t_parcouru		*parcouru;

// 	room(var->tabroom);
// 	way(var->tabconnect);
// 	printf("[ID START%d]\n", find_id(var->tabroom, var->start));
// 	printf("[ID END%d]\n", find_id(var->tabroom, var->end));
// 	start = find_room_hashtag(g_room_list, find_id(var->tabroom, var->start));
// 	end = find_room_hashtag(g_room_list, find_id(var->tabroom, var->end));
// 	parcouru = init_struct_parcours(start, var->fourmis);
// 	end->distance = 0;
// 	dijkstra(end, 0);
// 	display_algo(start, end, parcouru, var->fourmis);
// }

t_parsing *parsing(int fichier)
{
	char	*line;
	int		i;
	int		x;
	int		y;
	int		cline;
	char 	*temp;
	t_parsing	var;
	t_room			*start;
	t_room			*end;
	t_parcouru		*parcouru;

	var.start = NULL;
	var.end = NULL;
	var.fourmis = 0;
	// var.tab[0] = NULL;
	cline = 0;
	i = 0;
	y = 0;
	while (get_next_line(fichier, &line) != 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		if (var.fourmis == 0)
			var.fourmis = ft_fourmis(line);
		if (x == 1)
			var.start = ft_start_end(line);
		if (x == 2)
			var.end = ft_start_end(line);
		x = 0;
		if (ft_strcmp(line, "##start") == 0)
			x = 1;
		if (ft_strcmp(line, "##end") == 0)
			x = 2;
		if (countstr(line,' ') == 2 && line[0] != '#')
		{
			if (ft_tabchr(var.tabroom, ft_start_end(line)) != 0)
			{
				ft_putstr("ERROR CHAMBRE DEJA INIT - ON PEUT PAS CONTINUER\n");
				exit(0);
			}
			var.tabroom[y] = ft_start_end(line);
			y++;
		}
		var.tab = ft_strsplit(line, '-');
		if (var.tab[1] != NULL)
		{
			if (ft_tabchr(var.tabroom, var.tab[0]) == 0 || ft_tabchr(var.tabroom, var.tab[1]) == 0)
			{
				ft_putstr("ERROR CHAMBRE NON INIT\n");
				ft_error(&var);
			}
			var.tabconnect[i] = var.tab[0];
			i++;
			var.tabconnect[i] = var.tab[1];
			i++;
			free(var.tab);
		}
		else
			free(var.tab);
		// free(line);
	}
	var.tabconnect[i] = NULL;
	printf("-----------------------FIN LECTURE-----------------------\n");
	printf("[TAB END%s]\n",var.tabconnect[i]);
	if (var.start == NULL || var.end == NULL)
	{
		ft_putstr("ERROR START OU END\n");
		ft_error(&var);
	}
	printf("[Start %s]\n",var.start);
	printf("[End %s]\n",var.end);
	i = 0;
	while (var.tabroom[i])
	{
		printf("[%s]",var.tabroom[i]);
		i = i + 1;
	}
	printf("\n");
	printf("\n");
	i = 0;
	while (var.tabconnect[i])
	{
		printf("[%s]",var.tabconnect[i]);
		i = i + 1;
	}
	printf("\n");
	test(&var);
	// room(var.tabroom);
	// way(var.tabconnect);
	// printf("[ID START%d]\n", find_id(var.tabroom, var.start));
	// printf("[ID END%d]\n", find_id(var.tabroom, var.end));
	// start = find_room_hashtag(g_room_list, find_id(var.tabroom, var.start));
	// end = find_room_hashtag(g_room_list, find_id(var.tabroom, var.end));
	// parcouru = init_struct_parcours(start, var.fourmis);
	// end->distance = 0;
	// dijkstra(end, 0);
	// display_algo(start, end, parcouru, var.fourmis);
	return (0);
}

int main()
{
	int 	fichier;

	fichier = open("./maptest", O_RDONLY);
	parsing(fichier);
}