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

NAME	=	fillit

FLAGS	=	-Wall -Werror -Wextra -I./headers

SRCDIR	=	./sources/

OBJDIR	=	./objects/

LIBDIR	=	./libft-gnl/

SRC		=	execute_algorithm.c fill_struct.c main.c set_tetriminos.c read_file.c

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

LIB		=	libft.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBDIR)$(LIB)
	gcc -o $(NAME) $(OBJ) $(LIBDIR)$(LIB) $(FLAGS)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	gcc -o $@ -c $< $(FLAGS)

$(LIBDIR)$(LIB):
	make -C $(LIBDIR)

$(OBJDIR):
	mkdir $(OBJDIR) 

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -rf $(NAME)

re: fclean $(NAME)