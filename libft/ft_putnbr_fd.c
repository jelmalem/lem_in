/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:22:11 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/09 02:22:11 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	ft_putnbraux_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
	{
		ft_putchar_fd(48, fd);
		return ;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	tab[12];
	int		tmp;
	int		mod;
	int		c;

	if (n == -2147483648)
		ft_putnbraux_fd(n, fd);
	i = 0;
	tmp = n;
	if (n < 0)
		n = -n;
	if (n == 0)
		ft_putnbraux_fd(n, fd);
	while (n >= 1)
	{
		mod = n % 10;
		n = n / 10;
		c = mod + '0';
		tab[i++] = c;
	}
	if (tmp < 0)
		ft_putchar_fd('-', fd);
	while (tab[--i])
		ft_putchar_fd(tab[i], fd);
}
