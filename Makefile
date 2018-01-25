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

SRC_NAME = get_coordinates.c \
main.c \
print.c \
solver.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

DEPS = Includes/libft.h \
Includes/fillit.h \

CPPFLAGS = -IIncludes

SRC_PATH = SRC

NAME = fillit

LIB = SRC/libft

LIB_A = libft.a

FLAG = -Wall -Werror -Wextra

OBJ = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_PATH = obj

all: library $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc $(OBJ) $(LIB)/$(LIB_A) -o $(NAME) -Ifillit.h

library:
	make -C SRC/libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAG) -o $@ -c $< $(CPPFLAGS)

clean:
	make clean -C $(LIB)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(LIB)/$(LIB_A)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re
