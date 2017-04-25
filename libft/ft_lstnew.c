/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:00:55 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/12 21:00:55 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_element;

	if (!(new_element = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_element->content = NULL;
		new_element->content_size = 0;
		new_element->next = NULL;
	}
	else
	{
		if ((new_element->content = malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(new_element->content, content, content_size);
		new_element->content_size = content_size;
		new_element->next = NULL;
	}
	return (new_element);
}
