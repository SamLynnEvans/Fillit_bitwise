/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:30:02 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/18 20:26:56 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
	print_map(map, size);
	print_board(tets, size, map_count);
	return (size < 17) ? 1 : -1;
}

int	main(int ac, char **argv)
{
	int			fd;
	int			map_count;
	int			ret;
	char		buff[BUFF_SIZE];

	if (ac == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			error_and_exit();
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if ((map_count = check_format(buff)) == -1 || map_count > 26)
			error_and_exit();
		
		close(fd);
		if (setup_solver(buff, map_count) == -1)
			error_and_exit();
	}
	else
		ft_putstr("usage: fillit map_file\n");
	exit(EXIT_SUCCESS);
}
