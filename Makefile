# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 19:39:18 by oandrosh          #+#    #+#              #
#    Updated: 2019/03/18 15:37:48 by oandrosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra -g

SRC = source/depature.c source/errors.c source/links.c source/main.c\
	  source/output.c source/queue.c source/reading_map.c source/room.c\
	  source/start.c

OBJ = $(SRC:%.c=%.o) 

all: $(NAME)

%.o:%.c
	@gcc -c $(FLAGS) $< -o $@

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(OBJ) libft/libft.a -o $(NAME)

clean: 
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
