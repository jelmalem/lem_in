/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 05:46:06 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/09 05:46:06 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)))
		return (NULL);
	i = -1;
	while (*s1)
	{
		s3[++i] = *s1;
		s1++;
	}
	while (*s2)
	{
		s3[++i] = *s2;
		s2++;
	}
	s3[++i] = '\0';
	return (s3);
}
