/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_second.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:04:32 by jelmalem          #+#    #+#             */
/*   Updated: 2017/01/10 14:04:32 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_fourmis(char *line)
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
		if (fourmis == 0 || ft_isdigit(line[i]) != 1)
		{
			ft_putstr("ERROR - FOURMIS\n");
			exit(0);
		}
		i++;
	}
	return (fourmis);
}

char		*ft_start_end(char *line)
{
	char	*val;
	char	**t;

	t = ft_strsplit(line, ' ');
	if (t[1] != NULL && ft_is_number(t[1]) != 0 && ft_is_number(t[2]) != 0)
	{
		val = t[0];
		free(t);
	}
	else
	{
		free(t);
		ft_putstr("ERROR\n");
		exit(0);
	}
	return (val);
}

int			ft_verifline(char *line)
{
	char **t;

	if (line[0] == '#')
		return (0);
	if (ft_strcmp(line, "##start") == 0)
		return (0);
	if (ft_strcmp(line, "##end") == 0)
		return (0);
	if (countstr(line, ' ') == 2)
	{
		t = ft_strsplit(line, ' ');
		if (t[1] != NULL && ft_is_number(t[1]) != 0 && ft_is_number(t[2]) != 0)
			return (0);
		else
			return (1);
		free(t);
	}
	t = ft_strsplit(line, '-');
	if (t[1] != NULL)
	{
		free(t);
		return (0);
	}
	free(t);
	return (1);
}

int			parsing_ter(char *line, t_parsing *var, int i, t_seclist *list)
{
	char	**t;

	t = ft_strsplit(line, '-');
	if (t[1] != NULL)
	{
		if (t[3] != NULL)
		{
			ft_printf("ERROR\n");
			exit(0);
		}
		if (ft_tabchr(var->tabroom, t[0]) == 0 ||
			ft_tabchr(var->tabroom, t[1]) == 0)
		{
			ft_putstr("ERROR - CHAMBRE NON INIT\n");
			ft_error(var, list);
		}
		if (ft_strcmp(t[0], t[1]) == 0)
		{
			ft_putstr("ERROR - LIAISON MEME ROOM\n");
			ft_error(var, list);
		}
		var->tabconnect[i] = t[0];
		i++;
		var->tabconnect[i] = t[1];
		i++;
		free(t);
	}
	else
		free(t);
	return (i);
}

int			parsing_bis(char *line, t_parsing *var, int y)
{
	static int x;

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
	if (countstr(line, ' ') == 2 && line[0] != '#')
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
