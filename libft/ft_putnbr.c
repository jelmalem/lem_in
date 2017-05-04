/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:15:27 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/08 23:15:27 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void		ft_display_big_nb(unsigned int nb)
{
	unsigned int width_nb;
	unsigned int nb_bis;

	width_nb = 1;
	nb_bis = nb;
	while ((nb_bis /= 10) > 0)
	{
		width_nb *= 10;
	}
	while (width_nb != 0)
	{
		ft_putchar((nb / width_nb) % 10 + '0');
		width_nb /= 10;
	}
}

void			ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	ft_display_big_nb(nb);
}
