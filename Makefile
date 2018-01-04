# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 11:12:50 by slynn-ev          #+#    #+#              #
#    Updated: 2018/01/04 14:51:55 by slynn-ev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_coordinates.c \
main.c \
print.c \
solver.c \

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