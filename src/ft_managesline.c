/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managesline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by jelmalem          #+#    #+#             */
/*   Updated: 2017/05/04 11:01:42 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_seclist		*insertion(t_seclist *list, char *nvnombre)
{
	t_seclist	*tmp;
	t_seclist	*elem;

	if (!(elem = (t_seclist*)malloc(sizeof(t_seclist))))
		error();
	elem->line = ft_strdup(nvnombre);
	elem->next = NULL;
	if (list == NULL)
		return (elem);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}

void			printfile(t_seclist *list)
{
	while (list)
	{
		ft_printf("%s\n", list->line);
		list = list->next;
	}
}

void			error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}
