#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ollevche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 17:11:38 by ollevche          #+#    #+#              #
#    Updated: 2018/01/12 12:30:16 by ollevche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = execute_algorithm.c fill_struct.c main.c set_tetriminos.c read_file.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc -o $(NAME) $(OBJ) $(FLAG) $(LIB)

$(OBJ): $(SRC)
	gcc -c $(SRC)

$(LIB):
	make -C ./libft/

clean:
	make -C ./libft/ clean
	rm -rf *.o

fclean: clean
	make -C ./libft/ fclean
	rm -rf $(NAME)

re: fclean $(NAME)