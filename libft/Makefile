# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 14:30:02 by lobenard          #+#    #+#              #
#    Updated: 2024/12/02 14:30:02 by lobenard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iincludes
NAME = libft.a

# Fonctions pour obtenir les fichiers sources
SRC_DIRS = src/ft_is src/ft_mem src/ft_put src/ft_str src/ft_to
SRC = $(shell find $(SRC_DIRS) -name '*.c')
OBJS = $(SRC:.c=.o)

# Fichiers bonus
BSRC = $(wildcard src/ft_lst/*.c)
BOBJS = $(BSRC:.c=.o)

# Règles
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(BOBJS)
	ar rc $(NAME) $(BOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
