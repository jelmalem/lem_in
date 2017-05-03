/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:43:23 by jelmalem          #+#    #+#             */
/*   Updated: 2014/11/17 16:50:12 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*save;

	save = s1;
	while (*s1)
		s1++;
	while (n > 0 && *s2 != '\0')
	{
		*s1++ = *s2++;
		--n;
	}
	*s1 = '\0';
	return (save);
}
