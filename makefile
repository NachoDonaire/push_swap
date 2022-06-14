SRCS	=	functions.c functions_utils.c ft_atoi.c
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
