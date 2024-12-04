# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:09:04 by lobenard          #+#    #+#              #
#    Updated: 2024/12/04 18:14:58 by lobenard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 

NAME = libftprintf.a

OBJS	= $(SRC:.c=.o)

.c.o	:
		cc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

