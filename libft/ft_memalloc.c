/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:50:52 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/09 02:50:52 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		*ft_memalloc(size_t size)
{
	void	*v;

	if (size == 0)
		return (NULL);
	if ((v = malloc(size)) == NULL)
		return (NULL);
	if (v == NULL)
		return (NULL);
	ft_memset(v, 0, size);
	return (v);
}
