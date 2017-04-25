/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:05:42 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/09 02:05:42 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	count;

	if (!s || fd < 0)
		return ;
	count = 0;
	while (s[count])
	{
		ft_putchar_fd(s[count], fd);
		count = count + 1;
	}
}
