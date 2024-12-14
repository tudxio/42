# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobenard <lobenard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:09:04 by lobenard          #+#    #+#              #
#    Updated: 2024/12/13 19:06:13 by lobenard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile de printf

NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -Ilibft
AR				=	ar rc
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_printf.c ft_printchar.c ft_printstr.c ft_printptr.c ft_printnbr.c 			

OBJS	= $(SRC:.c=.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(LIBFT)

$(LIBFT): 
					make -C $(LIBFT_PATH)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJS)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft


