# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 15:03:28 by oandrosh          #+#    #+#              #
#    Updated: 2019/03/18 15:40:02 by oandrosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	  ft_isprime.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c\
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
	  ft_memmove.c ft_memset.c ft_onestr.c ft_putchar.c ft_putchar_fd.c\
	  ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
	  ft_putstr_fd.c ft_strsort.c ft_strcat.c ft_strchr.c ft_strclr.c\
	  ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
	  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c\
	  ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c\
	  ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c\
	  ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
	  ft_toupper.c ft_pow.c ft_abs.c ft_printf/ft_char.c ft_printf/ft_dec.c\
	  ft_printf/ft_decimal.c ft_printf/ft_defsize.c ft_printf/ft_flags.c\
	  ft_printf/ft_float.c ft_printf/ft_ftoa.c ft_printf/ft_hex.c\
	  ft_printf/ft_hh_hexal.c ft_printf/ft_hh_decimal.c\
	  ft_printf/ft_hh_octal.c ft_printf/ft_hh_un_decimal.c\
	  ft_printf/ft_itoa_long.c ft_printf/ft_join.c ft_printf/ft_oct.c\
	  ft_printf/ft_octal.c ft_printf/ft_point.c ft_printf/ft_printf.c\
	  ft_printf/ft_hexal.c ft_printf/ft_un_decimal.c ft_printf/ft_un_dec.c\
	  ft_printf/ft_string.c ft_printf/ft_itoa_base.c get_next_line.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(OBJ):%.o:%.c
	@gcc -g -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
