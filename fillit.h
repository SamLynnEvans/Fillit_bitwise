/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:30:10 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/04 14:50:20 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# define BUFF_SIZE 1000
#define WHT   "\x1B[37m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"

typedef struct	s_tetrimino t_tetrimino;

struct			s_tetrimino
{
	uint64_t			coords;
	unsigned char		last_piece;
	unsigned char		x;
	unsigned char		y;
	unsigned char		x_max;
	unsigned char		y_max;
	unsigned char		order;
	unsigned char		print_offset;
};

void			print_board(t_tetrimino *tets, int size, int map_count);
void			toggle_tet(const t_tetrimino *tets, uint16_t *map);
int 			can_place(const t_tetrimino *tets, uint16_t *map);
int				setup_solver(char *buff, int map_count);
int				get_coordinates(char *buff,
t_tetrimino *tets, int mc);

#endif
