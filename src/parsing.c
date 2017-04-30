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

void test(t_parsing *var)
{
	t_room			*start;
	t_room			*end;
	t_parcouru		*parcouru;

	room(var->tabroom);
	way(var->tabconnect);
	// printf("[ID START%d]\n", find_id(var->tabroom, var->start));
	// printf("[ID END%d]\n", find_id(var->tabroom, var->end));
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
			// printf("[Start %s]\n",var->start);
			// printf("[End %s]\n",var->end);
			ft_putstr("ERROR - On peut quand même lancer l'algo !\n");
			test(var);
			exit(0);
		}
	}
	else
	{
		ft_putstr("ERROR - On ne peut pas lancer l'algo\n");
		exit(0);
	}
}

int ft_fourmis(char *line)
{
	int fourmis;
	int i;

	i = 0;
	if (ft_strlen(line) == 0)
	{
		ft_putstr("ERROR - FOURMIS\n");
		exit(0);
	}
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1)
			fourmis = ft_atoi(line);
		if (fourmis == 0)
		{
			ft_putstr("ERROR - Il n'y a pas de fourmis!\n");
			exit(0);
		}
		else if (ft_isdigit(line[i]) != 1)
		{
			ft_putstr("ERROR - FOURMIS\n");
			exit(0);
		}
		i++;
	}
	// printf("[Fourmis %d]\n",fourmis);
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

int ft_verifline(char *line)
{
	char **tab;
	if (line[0] == '#')
		return(0);
	if (ft_strcmp(line, "##start") == 0)
		return(0);
	if (ft_strcmp(line, "##end") == 0)
		return(0);
	if (countstr(line,' ') == 2)
	{
		tab = ft_strsplit(line, ' ');
		if (tab[1] != NULL && ft_is_number(tab[1]) != 0 && ft_is_number(tab[2]) != 0)
		{
			free(tab);
			return(0);
		}
		else
		{
			free(tab);
			return(1);
		}
	}
	tab = ft_strsplit(line, '-');
	if (tab[1] != NULL)
	{
		free(tab);
		return(0);
	}
	free(tab);
	return(1);
}
int parsing_ter(char *line, t_parsing	*var, int i)
{
	char 		**tab;

	tab = ft_strsplit(line, '-');
	if (tab[1] != NULL)
	{
		if (ft_tabchr(var->tabroom, tab[0]) == 0 || ft_tabchr(var->tabroom, tab[1]) == 0)
		{
			ft_putstr("ERROR - CHAMBRE NON INIT\n");
			ft_error(var);
		}
		var->tabconnect[i] = tab[0];
		i++;
		var->tabconnect[i] = tab[1];
		i++;
		free(tab);
	}
	else
		free(tab);
	return(i);
}

int parsing_bis(char *line, t_parsing	*var, int y)
{

	static int x;
	// ft_printf("[Valeur de y %d]", y);
	// ft_printf("[Start %s]\n",var->start);
	// ft_printf("[End %s]\n",var->end);
	// ft_printf("LINE : %s\n",line);
	if (var->fourmis == 0)
		var->fourmis = ft_fourmis(line);
	if (x == 1)
		var->start = ft_start_end(line);
	if (x == 2)
		var->end = ft_start_end(line);
	x = 0;
	if (ft_strcmp(line, "##start") == 0)
		x = 1;
	if (ft_strcmp(line, "##end") == 0)
		x = 2;
	if (countstr(line,' ') == 2 && line[0] != '#')
	{
		if (ft_tabchr(var->tabroom, ft_start_end(line)) != 0)
		{
			ft_putstr("ERROR - CHAMBRE DEJA INIT - ON PEUT PAS CONTINUER\n");
			exit(0);
		}
		var->tabroom[y] = ft_start_end(line);
		y++;
	}
	return (y);
}

// void pre_parsing(int fichier, char *line, t_parsing	*var)
// {
// 	int x;
// 	int y;
// 	char **tab;

// 	x = 0;
// 	y = 0;
// 	while (get_next_line(fichier, &line) == 1)
// 	{
// 		if (countstr(line,' ') == 2 && line[0] != '#')
// 			y++;
// 		tab = ft_strsplit(line, '-');
// 		if (tab[1] != NULL)
// 		{
// 			x = x + 2;
// 			free(tab);
// 		}
// 	}
// 	var->tabroom = malloc(y * sizeof(char));
// 	var->tabconnect = malloc(x * sizeof(char));
// 	// ft_printf("[Valeur de y : %d]\n", y);
// 	// ft_printf("[Valeur de x : %d]\n", x);
// }


t_parsing *parsing(int fichier)
{
	char			*line;
	int				i;
	int				x;
	int				y;
	t_parsing		var;
	int back;

	var.start = NULL;
	var.end = NULL;
	var.fourmis = 0;
	i = 0;
	y = 0;
	x = 0;
	// ft_printf("[Fichier 1 : %d]\n",fichier);
	// pre_parsing(fichier, line, &var);
	// fichier = open("maptest", O_RDONLY);
	// ft_printf("[Fichier 2 : %d]\n",fichier);
	while (get_next_line(fichier, &line) == 1)
	{
		if (fichier != 0)
			ft_printf("%s\n",line);
		if (ft_verifline(line) == 1 && var.fourmis != 0)
		{
			ft_error(&var);
			exit(0);
		}
		y = parsing_bis(line, &var, y);
		i = parsing_ter(line, &var, i);
	}
	var.tabconnect[i] = NULL;
	// printf("-----------------------FIN LECTURE-----------------------\n");
	// printf("[Fourmis %d]\n",var.fourmis);
	if (var.start == NULL || var.end == NULL)
	{
		ft_putstr("ERROR - START OU END\n");
		ft_error(&var);
	}
	// printf("[Start %s]\n",var.start);
	// printf("[End %s]\n",var.end);
	// printf("\n");
	test(&var);
	return (0);
}

int	main(int argc, char *argv[])
{
	int 	fichier;
	
	if (argc == 1)
		parsing(0);
	else if (argc == 2)
	{
		fichier = open(argv[1], O_RDONLY);
		parsing(fichier);
	}
	else if (argc > 2)
	{
		ft_putstr("ERROR - Arg\n");
		exit(0);
	}
	fichier = 0;
}