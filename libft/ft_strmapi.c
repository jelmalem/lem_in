/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 04:26:00 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/09 04:26:00 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	char	*strnew;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (!(strnew = ft_strnew(size)))
		return (NULL);
	if (s && f)
	{
		while (s[i])
		{
			strnew[i] = f(i, s[i]);
			i++;
		}
	}
	return (strnew);
}
