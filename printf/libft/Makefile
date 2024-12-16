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

# Standard

NAME		=	libft.a
INCLUDES	=	../include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDES)
RM			=	rm -f
AR			=	ar rcs

# Sources

SRC_FILES	=	ft_memcpy \
				ft_calloc \
				ft_strnstr \
				ft_isalpha \
				ft_strtrim \
				ft_memmove \
				ft_isalnum \
				ft_isdigit \
				ft_isprint \
				ft_tolower \
				ft_toupper \
				ft_strncmp \
				ft_strlen \
				ft_bzero \
				ft_memset \
				ft_substr \
				ft_strmapi \
				ft_strchr \
				ft_atoi \
				ft_isascii \
				ft_itoa \
				ft_strjoin \
				ft_split \
				ft_memchr \
				ft_strrchr \
				ft_striteri \
				ft_strdup \
				ft_memcmp \
				ft_strlcpy \
				ft_strlcat \
				ft_putstr_fd \
				ft_putchar_fd \
				ft_putendl_fd \
				ft_putnbr_fd \
				ft_striteri \
				ft_lstnew_bonus \
				ft_lstsize_bonus \
				ft_lstadd_front_bonus \
				ft_lstlast_bonus \
				ft_lstadd_back_bonus \
				ft_lstclear_bonus \
				ft_lstdelone_bonus \
				ft_lstiter_bonus \
				ft_lstmap_bonus

SRC 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all

norm:
	@norminette $(SRC) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

