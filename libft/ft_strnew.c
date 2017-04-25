/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:20:26 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/09 03:20:26 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*v;

	v = (char *)malloc(size + 1);
	if (v == NULL)
		return (NULL);
	ft_memset(v, (int)'\0', size + 1);
	return (v);
}
