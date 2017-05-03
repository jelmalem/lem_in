/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:01:44 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/09 06:01:44 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char			*ft_strtrimzero(void)
{
	char			*tab;

	if (!(tab = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	tab[0] = '\0';
	return (tab);
}

static int			ft_start(char const *s)
{
	int				i;
	int				start;

	i = 0;
	while ((s[i] == ' ') || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	return (start);
}

static int			ft_end(char const *s, int len)
{
	int				i;
	int				end;

	i = 1;
	while (s[len - i] == ' ' || s[len - i] == '\n' || s[len - i] == '\t')
		i++;
	end = (len - i + 1);
	return (end);
}

char				*ft_strtrim(char const *s)
{
	char			*tab;
	int				i;
	int				start;
	int				end;
	int				len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (ft_strlen(s) == 0)
		return (ft_strtrimzero());
	start = ft_start(s);
	if (start == len)
		end = start;
	else
		end = ft_end(s, len);
	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (start != end)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
