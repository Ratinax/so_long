NAME=libft.a

CC=cc

CFLAGS=-Wall -Werror -Wextra

SRCS=ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstsize.c \
	ft_printf.c \
	ft_put_params.c

SRCBONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

BONUSOBJS=${SRCBONUS:.c=.o}

HEADER = libft.h

INCLUDES = .

OBJS=${SRCS:.c=.o}

DIROBJS=objs/

AR=ar

ARFLAGS=-rcs

all: ${NAME}

${NAME}:	${DIROBJS} ${addprefix ${DIROBJS}, ${OBJS}}
	${AR} ${ARFLAGS} ${NAME} ${addprefix ${DIROBJS}, ${OBJS}}
	ranlib ${NAME}

${DIROBJS}%.o:	%.c ${HEADER} Makefile
	${CC} -o $@ -I ${INCLUDES} -c $< ${CFLAGS}

${DIROBJS}:
	mkdir ${DIROBJS}

clean:
	-rm -rf ${DIROBJS}

fclean: clean
	-rm -f ${NAME}

re:	fclean all

bonus:	${DIROBJS} ${addprefix ${DIROBJS}, ${BONUSOBJS}} ${addprefix ${DIROBJS}, ${OBJS}}
	${AR} ${ARFLAGS} ${NAME} ${addprefix ${DIROBJS}, ${BONUSOBJS}} ${addprefix ${DIROBJS}, ${OBJS}}

.PHONY:	all clean fclean re bonus
