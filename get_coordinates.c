/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:29:32 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/18 17:48:21 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	get_points(int *start, t_tetrimino *tets, char *buff)
{
	int	i;
	int	count;
	int	x_min;
	int	coords[4];

	count = 0;
	i = -1;
	while (++i < 20)
		if (buff[i] == '#')
			coords[count++] = i;
	tets->x_max = coords[0] % 5;
	x_min = coords[0] % 5;
	i = -1;
	while (++i < 4)
	{
		tets->x_max = (tets->x_max < coords[i] % 5) ? coords[i] % 5 : tets->x_max;
		x_min = (x_min > coords[i] % 5) ? coords[i] % 5 : x_min; 
	}
	tets->print_offset = (coords[0] % 5 - x_min);
	*start = coords[0] - (coords[0] % 5 - x_min);
	tets->x_max = tets->x_max - x_min;
	tets->y_max = ((coords[3] + 1) / 5) - ((coords[0] + 1) / 5);
	return ((count == 4) ? 1: 0);
}

int assign_coords(t_tetrimino *tets, char *buff)
{
	int	pos;
	int	x;
	int	y;
	uint64_t	num;

	if (!(get_points(&pos, tets, buff)))
		return (-1);
	y = tets->y_max;
	while (y >= 0)
	{
		num = 0;
		x = 0;
		while (x <= tets->x_max)
		{
			if (buff[pos + (y * 5) + x] == '#')
				num = num | 1UL << (tets->x_max - x);
			x++;
		}
			num = num << ((16 * (y + 1)) - (tets->x_max + 1));
			tets->coords += num;
		y--;
	}
	return (1);
}

int	get_coordinates(char *buff, t_tetrimino *tets, int map_count)
{
	int	j;

	j = 0;
	while (j < map_count)
	{
		assign_coords(&tets[j], buff);	
		tets[j].order = j;
		ft_memmove(buff, &buff[21], ft_strlen(buff) + 1);
		tets[j].last_piece = (j + 1 == map_count) ? 1 : 0;
		j++;
	}
	return (1);
}
