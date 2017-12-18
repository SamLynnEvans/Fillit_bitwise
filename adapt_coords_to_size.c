/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_coords_to_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:48:31 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/17 22:58:21 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

void	fill_tetrimino_struct(uint64_t num, t_tetrimino *tets)
{
	int			n;
	int			x;
	int			y;
	int			first_time;
	uint64_t	mask;

	mask = 1;
	first_time = 0;
	x = 0;
	n = 0;
	while (n < 64)
	{
		if (mask << n & num)
		{
			if (first_time == 0)
			{
				first_time = 1;
				y = (n / 16);
			}
			x = (x < 16 - (n % 16)) ? 16 - n  % 16 : x;		
		}
		n++;
	}
	tets->x_max = x - 1;
	tets->y_max = 4 - (y + 1);
	tets->coords = num >> (y * 16);
//	tets->coords = num;
//	printf("%llu\n", tets->coords);
}

void	adapt_coords_to_size(uint64_t n, t_tetrimino *tets)
{
	uint64_t		num;
	int				j;
	int				mask;
	int				i;


	i = 1;
	j = 4;
	num = 0;
	while (j <= 16)
	{
		mask = (1 << 15) + (1 << 15) - (1 << j);
		num += ((n & ~(mask))>>(j - 4))<<(j - 4 + 12 * i++);
		j += 4;
	}
	fill_tetrimino_struct(num, tets);
	//	printf("num = %llu\n", num);	
}
/*
   int main()
   {
   uint64_t	num = 11776;

   adapt_coords_to_size(num, 16);
   }*/
