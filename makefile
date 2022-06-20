SRCS	=	functions.c ft_atoi.c binario.c result.c find_max.c dec.c
OBJS	=	${SRCS:.c=.o}
NAME	=	push_swap
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror 
.c.o:
	${CC} ${CFLAGS} -c ${SRCS}
all:	${NAME}
$(NAME):	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}
clean:
	${RM} ${OBJS}
fclean:
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
