# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbeall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 14:21:53 by jbeall            #+#    #+#              #
#    Updated: 2018/11/13 12:35:12 by jbeall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra
SRC = ./src/fillit.c ./src/fillit_reader.c ./src/fillit_solver.c
INCLUDES = ./includes/fillit.h ./libft/libft.a

$(NAME):
	make -C ./libft
	gcc -o $(NAME) $(FLAGS) $(SRC) -I$(INCLUDES)
all: $(NAME)
test: fclean
	make -C ./libft
	gcc -o $(NAME) $(FLAGS) -g ./fillit_extras.c $(SRC) -I$(INCLUDES) -O3
	./fillit ./maps/valid4
clean:
	make clean -C ./libft
fclean: clean 
	rm -f $(NAME)
	make fclean -C ./libft
re: fclean all