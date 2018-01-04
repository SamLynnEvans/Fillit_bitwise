/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:43:28 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/04 14:50:01 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

inline int can_place(const t_tetrimino *tets, uint16_t *map)
{
	return (!(*(uint64_t *)(map + tets->y) & (tets->coords >> tets->x)));
}

inline void	toggle_tet(const t_tetrimino *tets, uint16_t *map)
{
	*(uint64_t *)(map + tets->y) ^= (tets->coords >> tets->x);
}

int	backtrack_filler(t_tetrimino *tets, int size, uint16_t *map)
{	
	tets->y = 0;
	while (tets->y + tets->y_max < size)
	{
		tets->x = 0;
		while (tets->x + tets->x_max < size)
		{
			if (can_place(tets, map))
			{
				toggle_tet(tets, map);
				if (tets->last_piece == 1)
					return (1);
				if (backtrack_filler(tets + 1, size, map))
					return (1);
				toggle_tet(tets, map);
			}
			tets->x++;
		}
		tets->y++;
	}
	return (0);
}

int	get_size(int map_count)
{
	int num;
	int minimum_area;

	minimum_area = map_count * 4;
	num = 0;
	while (1)
	{
		if (num * num >= minimum_area)
			break ;
		num++;
	}
	return (num);
}

int	setup_solver(char *buff, int map_count)
{
	uint16_t		map[16];
	t_tetrimino		tets[map_count];
	int				size;
	
	size = get_size(map_count);
	if (!(get_coordinates(buff, tets, map_count)))
		return (-1);
	ft_bzero(map, sizeof(uint16_t) * 16);
	while ((backtrack_filler(tets, size, map)) == 0 && size < 17)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	if (size < 17)
	{
		print_board(tets, size, map_count);
		return (1);
	}
	return (0);
}
