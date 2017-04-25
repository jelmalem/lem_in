/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:44:37 by jelmalem          #+#    #+#             */
/*   Updated: 2014/11/17 18:02:56 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	length_total;

	length = 0;
	length_total = ft_strlen(src) + ft_strlen(dst);
	while (length < size && *dst)
	{
		dst++;
		length++;
	}
	if (size <= length)
		return (size + ft_strlen(src));
	while (length < (size - 1) && *src)
	{
		*dst++ = *src++;
		length++;
	}
	*dst = '\0';
	return (length_total);
}
