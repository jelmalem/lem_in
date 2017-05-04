/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:31:31 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/15 17:27:58 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, ssize_t len)
{
	char	*s3;
	char	*temp;

	s3 = ft_strnew(ft_strlen(s1) + len);
	temp = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2 && len > 0)
	{
		*s3++ = *s2++;
		len--;
	}
	*s3 = '\0';
	return (s3 - (s3 - temp));
}
