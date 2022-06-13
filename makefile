SRCS	=	functions.c functions_utils.c
OBJS	=	${SRCS:.c=.c}
NAME	=	push_swap ft_atoi.c
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
re: fclean all
.PHONY: all clean fclean re
