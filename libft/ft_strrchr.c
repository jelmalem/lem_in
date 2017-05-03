/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:33:12 by jelmalem          #+#    #+#             */
/*   Updated: 2014/11/17 16:52:44 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		end_count;

	if (c < 0 || c > 127)
		return (NULL);
	end_count = ft_strlen(s);
	while (end_count >= 0)
	{
		if (s[end_count] == (char)c)
			return ((char *)&s[end_count]);
		end_count--;
	}
	return (NULL);
}
