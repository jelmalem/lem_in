/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:38:43 by jelmalem          #+#    #+#             */
/*   Updated: 2014/11/17 18:03:43 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] && ((ft_strlen(s2) + i - 1) < n))
	{
		if (s1[i] == *s2)
		{
			if (ft_strncmp(&s1[i], s2, ft_strlen(s2)) == 0)
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
