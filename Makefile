NAME = libftprintf.a

SRC = ft_printf.c printf_utility.c ft_printf.h

CFLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -f

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

LIB = ar rc ${NAME}

${NAME}: ${OBJ}
	${LIB} ${OBJ}

all: ${NAME}


clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
