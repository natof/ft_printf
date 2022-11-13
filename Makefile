# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrallo <nrallo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 12:46:06 by nrallo         #+#    #+#              #
#    Updated: 2022/10/19 13:48:20 by nrallo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC    = gcc
CFLAGS = -Wall -Werror -Wextra
NAME  = libftprintf.a
SRCS   = ft_printf.c \
		 ft_print_char.c \
		 ft_print_str.c \
		 ft_print_hexadecimal.c \
		 ft_itoa.c \
		 ft_strlen.c \
		 ft_print_pourcent.c \
		 ft_print_nbr_base.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f ./*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all