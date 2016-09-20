#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 20:50:24 by tguillot          #+#    #+#              #
#    Updated: 2016/09/20 17:26:22 by vleite           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = 	main.c \
		getnbr.c \
		pixel_put.c \
		print.c

OBJ = 	main.o \
		getnbr.o \
		pixel_put.o \
		print.o

HEADER = fdf.h\
		./libft/libft.h\

FINDLIBFT = -Llibft

LIBFTA = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror 

LIBFT_DIR = ./libft/

all: $(NAME)

$(NAME):
	@clear
	@echo "\033[35;4mRule all!\033[0m"
	@make fclean -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
	@gcc $(FLAGS) -c $(SRC) $(HEADER)
	@gcc -o $(NAME) $(OBJ) $(LIBFTA) -lmlx -framework OpenGL -framework AppKit 

clean:
	@clear
	@echo "\033[35;4mRule clean!\033[0m"
	@rm -f $(OBJ)
	@rm -f fdf.h.gch
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@clear
	@echo "\033[35;4mRule fclean!\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
	@clear
	@echo "\033[35;4mRules fclean and all!\033[0m"

.PHONY: all, clean, fclean, re