SRCS  = parcfun_1.c parcfun_2.c ft_build_linker.c \
	tools.c tools_1.c tools_2.c epur_str.c \
	parcing.c  tools_3.c switch_data.c parcer.c
OBJS	= ${SRCS:.c=.o}

FLAGS	= -g -Wall -Wextra -Werror -lreadline

NAME	= shell.a
HEAD	= ft_printf.h
CC = gcc
%.o: %.c ${HEAD}
	${CC} ${FLAGS} -c $< -o minishel;

$(NAME):${OBJS}
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
