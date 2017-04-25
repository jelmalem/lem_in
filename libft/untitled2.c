/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 14:41:04 by jelmalem          #+#    #+#             */
/*   Updated: 2017/02/26 14:42:53 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lem_in.h"

int ft_algo_2(int *tab, int *tab2, int start, int end, int z)
{
	int i;
	int X;
	static int b = 0;

	X = 0;
	i = 0;
	tab2[0] = start;
	while (tab[i] < 10 && X == 0)
	{
		if (tab2[b] == tab[i])
		{
			if (tab[i+1] == end)
			{
				tab2[b+1] = end;
				return(1);
				X = 1;
			}
		}
		i = i + 1 + z;
	}
	i = 0;
	while (tab[i] < 10 && X == 0)
	{
		if (tab2[b] == tab[i])
		{
			b++;
			X = 1;
			tab2[b] = tab[i+1];
		}
		i = i + 1 + z;
	}
	i = 0;
	return(0);
}
int *ft_algo()
{
	char *tab;
	char *tab2;
	int start;
	int end;
	int r;
	int z;
	int i;

	z=0;
	r = 0;
	start = 0;
	end = 1;
	tab =(char*)malloc(sizeof(char) * 10);
	tab2 =(char*)malloc(sizeof(char) * 10);
	
	tab[0] = '0';
	tab[1] = 2;

	tab[2] = 0;
	tab[3] = 3;

	tab[4] = 2;
	tab[5] = 3;

	tab[6] = 3;
	tab[7] = 1;

	tab[8] = 2;
	tab[9] = 4;
	tab2[0] = start;
	while (r != 1)
	{
		r = ft_algo_2(tab, tab2, start, end, z);
		if (z == 1)
			z = 0;
		else
			z = 1;
	}
	i=0;
	while (i < 10)
	{
		printf("[%d]",tab[i]);
		i++;
	}
	printf("\n");
	printf("[%d]",tab2[0]);
	printf("[%d]",tab2[1]);
	printf("[%d]",tab2[2]);
	printf("[%d]",tab2[3]);
	printf("\n");
	free(tab);
	return(tab2);
}
void ft_print(int *tab)
{
	int fourmis;
	int i;
	int b;
	int room;
	int end;

	end = 1;
	fourmis = 3;
	i = 1;
	b = 1;

	while (i <= fourmis)
	{
		while (tab[b] != end)
		{
			printf("L%d-%d\n",i, tab[b]);
			b++;
		}
		printf("L%d-%d\n",i, tab[b]);
		b = 1;
		i++;
	}
	free(tab);
}

int main()
{
	ft_print(ft_algo());
}
