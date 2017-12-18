/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:25:44 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/17 23:21:49 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
long long binary_conversion(long long num)
{
	if (num == 0)
	{
		return 0;
	}
	else
	{
		return (num % 2) + 10 * binary_conversion(num / 2);
	}
}

int		assign_tetriminos(int map_count, t_tetrimino *tets,
		int *coordinates, int *tlib)
{
	int			i;
	int			j;

	i = 0;
	while (i < map_count)
	{
		j = -1;
		while (++j < 19)
		{
			if (check_for_match(coordinates[i], tlib[j]))
			{
				//				j = (j == 18) ? 12 : j;
				//				j = (j == 3) ? 5 : j;
				adapt_coords_to_size((uint64_t)tlib[j], tets + i);
				printf("tets[%d].coords = %llu\n", i, tets[i].coords);
				if (i + 1 == map_count)
					tets[i].last_piece = 1;
				else
					tets[i].last_piece = 0;
				break ;
			}
		}
		if (j == 19)
			return (0);
		i++;
	}
	return (1);
}
