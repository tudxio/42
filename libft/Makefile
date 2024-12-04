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

SRC	= ft_memcpy.c \
		ft_calloc.c \
		ft_strnstr.c \
		ft_isalpha.c \
		ft_strtrim.c \
		ft_memmove.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strncmp.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_memset.c \
		ft_substr.c \
		ft_strmapi.c \
		ft_strchr.c \
		ft_atoi.c \
		ft_isascii.c \
		ft_itoa.c \
		ft_strjoin.c \
		ft_split.c \
		ft_memchr.c \
		ft_strrchr.c \
		ft_striteri.c \
		ft_strdup.c \
		ft_memcmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_striteri.c\

BSRC = 	ft_lstnew_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstlast_bonus.c\

NAME	= libft.a

OBJS	= $(SRC:.c=.o)

BOBJS	= $(BSRC:.c=.o)

.c.o	:
		cc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

bonus : ${BOBJS}
		ar rc ${NAME} ${BOBJS}

all : ${NAME}

clean :
		rm -f ${OBJS} ${BOBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all
