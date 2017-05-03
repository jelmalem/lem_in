/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managesline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by jelmalem          #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

tsecond_list *insertion(tsecond_list *list, char *nvNombre)
{
    tsecond_list      *tmp;
    tsecond_list      *elem;

    elem = (tsecond_list*)malloc(sizeof(tsecond_list));
    elem->line = ft_strdup(nvNombre);
    elem->next = NULL;
    if (list == NULL)
        return (elem);
    tmp = list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
    return (list);
}

void printfile(tsecond_list *list)
{
    while (list)
    {
        ft_printf("%s\n", list->line);
        list = list->next;
    }
}