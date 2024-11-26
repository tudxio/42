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
