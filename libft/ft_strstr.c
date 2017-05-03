/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 15:00:34 by jelmalem          #+#    #+#             */
/*   Updated: 2014/11/17 17:01:59 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
