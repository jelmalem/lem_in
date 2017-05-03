/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:36:31 by jelmalem          #+#    #+#             */
/*   Updated: 2014/11/16 18:12:58 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)s1 + count) = *((unsigned char *)s2 + count);
		if (*((unsigned char *)s2 + count) == (unsigned char)c)
			return ((unsigned char *)s1 + count + 1);
		count++;
	}
	return (NULL);
}
