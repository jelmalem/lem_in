/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/09 21:41:01 by jelmalem          #+#    #+#             */
/*   Updated: 2014/11/16 20:10:38 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(char *src)
{
	char	*s2;
	int		i;

	i = 0;
	if ((s2 = (char *)malloc((ft_strlen(src) + 1) * (sizeof(char)))))
	{
		while (src[i] != '\0')
		{
			s2[i] = src[i];
			++i;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
