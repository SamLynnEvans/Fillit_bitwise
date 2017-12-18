/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:30:10 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/18 20:27:49 by slynn-ev         ###   ########.fr       */
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

//void			print_square(char **square, int size);
void			print_board(t_tetrimino *tets, int size, int map_count);
void			adapt_coords_to_size(uint64_t n, t_tetrimino *tets);
void			toggle_tet(const t_tetrimino *tets, uint16_t *map);
int 			can_place(const t_tetrimino *tets, uint16_t *map);
int				print_map(uint16_t *tab, int size);
int				print_binary(uint64_t *tab, int map_count, int size);
void			binary_printer(uint64_t tab, int size);
//void			assign_tetrimino_index(t_tetrimino **tets, int size);
//void			n_print_square(char *square, int size);
void			free_tetriminos(t_tetrimino **tetriminos, int mc);
//void			free_square(char **square, int size);
//char			**build_square(int size);
void			error_and_exit(void);
void			build_tetrimino_library(int tets[19]);
int				get_size(int map_count);
int				check_format(char *buff);
int				get_coordinates(char *buff,
t_tetrimino *tets, int mc);
int				check_for_match(int input_coordinates, int tlib_coordinates);
int				assign_tetriminos(int map_count, t_tetrimino *tets,
int	*coordinates, int *tlib);
//int				put_tetrimino(t_tetrimino *tetrimino,
//char *square, int pos);
//void			remove_tetrimino(t_tetrimino *tetrimino,
//char *square, int pos);

#endif
