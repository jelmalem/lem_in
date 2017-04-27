/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:35:13 by jelmalem          #+#    #+#             */
/*   Updated: 2017/04/27 21:35:29 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_is_number(char *number)
{
	int i;

	i = 0;
	while (i < ft_strlen(number))
	{
		if (ft_isdigit(number[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}