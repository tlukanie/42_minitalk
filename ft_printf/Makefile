# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 18:14:21 by tlukanie          #+#    #+#              #
#    Updated: 2023/02/07 18:55:31 by tlukanie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c print_hexadecimal.c print_integer.c print_pointer.c \
		print_unsigned_num.c itoa_customized.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
INCS = ft_printf.h
LIBC = ar rc
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

%.o: %.c $(INCS)
	@$(CC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
bonus: all

re: fclean all

.PHONY: all clean fclean re
