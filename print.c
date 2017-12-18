/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:25:33 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/18 20:26:21 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_color(char c)
{
	char a;
	int  i;

	i = 0;
	a = c % 6;
	if (a == i++)
		printf(RED "%c", c);
	if (a == i++)
		printf(CYN "%c", c);
	if (a == i++)
		printf(YEL "%c", c);
	if (a == i++)
		printf(BLU "%c", c);
	if (a == i++)
		printf(MAG "%c", c);
	if (a == i++)
		printf(GRN "%c", c);
}

void	board_printer(char square[16][16], int size)
{
	int	j;
	int	i;

	j = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (square[j][i] < 'A' || square[j][i] > 'Z')
				printf(WHT ".");
			else
				print_color(square[j][i]);
			i++;
			printf(" ");
		}
		printf("\n");
		j++;
	}
}

void	print_board(t_tetrimino *tets, int size, int map_count)
{
	char square[16][16];
	int	j;
	int	n;
	ft_bzero(square, sizeof(char) * 16 * 16);
	j = 0;
	while (j < map_count)
	{
		n = 0;
		while (n < 16 * (tets[j].y_max + 1))
			{
				if (1ULL << n & tets[j].coords)
					square[tets[j].y + n / 16][tets[j].x + 15 - (n % 16)] = tets[j].order + 'A';
				n++;
			}
		j++;
	}
	board_printer(square, size);
}
