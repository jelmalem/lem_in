/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 05:09:45 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/09 05:09:45 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		i;
	int		count;

	if (!s || len == 0 || (ft_strlen(s) < (int)start))
		return (NULL);
	count = 0;
	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && count < (int)len)
	{
		tab[i] = s[start];
		start++;
		i++;
		count++;
	}
	tab[i] = '\0';
	return (tab);
}
