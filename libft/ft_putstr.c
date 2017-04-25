/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:01:06 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/03 18:01:06 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putstr(char const *s)
{
	int	count;

	if (!s)
		return ;
	count = 0;
	while (s[count])
	{
		ft_putchar(s[count]);
		count = count + 1;
	}
}
