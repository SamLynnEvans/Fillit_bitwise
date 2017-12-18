# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 11:12:50 by slynn-ev          #+#    #+#              #
#    Updated: 2017/12/18 20:27:23 by slynn-ev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = adapt_coords_to_size.c \
	assign_tetriminos.c \
	build_tetrimino_library.c \
	check_for_match.c \
   	check_format.c \
	error.c \
	get_coordinates.c \
	get_size.c \
	main.c \
	print_binary.c \
	print_map.c \
	print.c \

NAME = fillit
LIB = libft
LIB_A = libft.a
FLAG = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

all: library $(NAME)

$(NAME): $(OBJ) $(LIB)
	make -C $(LIB)
	gcc $(OBJ) $(LIB)/$(LIB_A) -o $(NAME) -Ifillit.h

library:
	make -C libft
%.o: %.c
	gcc -c $(FLAG) $<

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)/$(LIB_A)

re: fclean all

.PHONY: all clean fclean re
