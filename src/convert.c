/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:17:39 by jelmalem          #+#    #+#             */
/*   Updated: 2017/03/06 17:17:39 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int find_id(char **tabroom, char *name)
{	
	int i;

	i = 0;
	while (tabroom[i])
	{
		if (ft_strcmp(tabroom[i], name) == 0)
			return(i);
		i++;
	}
	return(-1);
}

void	room(char **tabroom)
{
	t_room		room;
	int i;

	i = 0;
	while (tabroom[i])
	{
		room.name = tabroom[i];
		room.x = 0;
		room.y = 0;
		room.distance = -1;
		room.next = NULL;
		room.id = i;
		room.next_voisin = NULL;
		g_id = 0;
		room_push_front(&g_room_list, &room);
		// printf("%s %d %d\n", room.name, room.x, room.y);
		i++;
		g_case_count++;
	}
}

void	way(char **tabconnect)
{
	t_room	*left;
	t_room	*right;
	int i;

	i = 0;
	while (tabconnect[i] != NULL)
	{
		left = room_exist(g_room_list, tabconnect[i]);
		right = room_exist(g_room_list, tabconnect[i+1]);
		if (left == NULL || right == NULL)
		{
			ft_putstr("ERROR\n");
			exit(0);
		}
		voisin_push_front(&left->next_voisin, right);
		voisin_push_front(&right->next_voisin, left);
		// printf("%s-%s\n", left->name, right->name);
		i = i + 2;
	}
}
