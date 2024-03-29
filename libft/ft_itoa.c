/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:35:46 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/12 20:35:46 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void		ft_itoa_fill(int width, int n, char *str)
{
	while (width--)
	{
		str[width] = (n % 10) + '0';
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		n_bis;
	int		width;
	int		is_negativ;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	width = 1;
	is_negativ = 0;
	if (n < 0)
		is_negativ = 1;
	if (is_negativ)
		n = -n;
	n_bis = n;
	while ((n_bis /= 10) > 0)
		width++;
	if (is_negativ)
		width++;
	if (!(str = (char *)malloc(sizeof(char) * width + 1)))
		return (NULL);
	str[width] = '\0';
	ft_itoa_fill(width, n, str);
	if (is_negativ)
		str[0] = '-';
	return (str);
}
