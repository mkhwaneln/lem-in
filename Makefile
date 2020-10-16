# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 10:58:13 by lmkhwane          #+#    #+#              #
#    Updated: 2018/07/18 14:39:35 by lmkhwane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAGS = -Wall -Werror -Wextra

SRC = main.c ft_input.c free_utils.c utils.c get_info.c link.c calc.c move.c \
	  get_next_line.c

OBJ = main.o ft_input.o free_utils.o utils.o get_info.o link.o calc.o move.o \
	  get_next_line.o

HEADER = lem-in.h

LIB = ./libft/libft.a

all: $(NAME)

$(NAME):
	@echo "Creating lem-in........"
	@make -C libft/
	@gcc -o $(NAME) $(SRC) $(FLAGS) $(LIB)
	@echo "lem-in created"

clean:
	@echo "Removing lem_in object files....."
	@rm -rf $(OBJ)
	@echo "lem_in object files removed"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(NAME) removed"

re: fclean all
