# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jackson <jbeall@student.42.us.org>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 14:21:53 by jbeall            #+#    #+#              #
#    Updated: 2018/11/16 16:09:17 by jackson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra
SRC = ./src/fillit.c ./src/fillit_reader.c ./src/fillit_solver.c
INCLUDES = ./includes
LIBRARIES = ./libft/libft.a

$(NAME):
	@make -C ./libft --no-print-directory
	@echo "Creating fillit executable..."
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIBRARIES) -I$(INCLUDES)
	@echo "\033[92mdone!\033[0m"
all: $(NAME)
test: fclean
	make -C ./libft --no-print-directory
	gcc -o $(NAME) $(FLAGS) -g ./fillit_extras.c $(SRC) -I$(INCLUDES) -O3
	./fillit ./maps/valid4
clean:
	@echo "cleaning..."
	@make clean -C ./libft --no-print-directory
	@echo "libft object files removed!"
fclean: clean 
	@rm -f $(NAME)
	@echo "fillit executable removed!"
	@make fclean -C ./libft --no-print-directory
re: fclean all