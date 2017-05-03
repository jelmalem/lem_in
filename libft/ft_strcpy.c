/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 03:59:54 by jelmalem          #+#    #+#             */
/*   Updated: 2014/09/03 21:20:49 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int src_length;

	src_length = 0;
	while (src[src_length] != '\0')
	{
		dest[src_length] = src[src_length];
		src_length++;
	}
	dest[src_length] = '\0';
	return (dest);
}
