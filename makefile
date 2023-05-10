SRCS	=	functions.c ft_atoi.c binario.c result.c find_max.c dec.c desmap.c main.c handle_push.c general_bit.c first_bit_bucle.c no_repeat.c is_sorted.c push_swap.c few_nums.c max_int.c sort_a.c reals.c ft_split.c ft_calloc.c ft_memcpy.c
DSRC 	= 	src/
DSRCS = 	$(addprefix $(DSRC), $(SRCS))
OBJS	=	${DSRCS:.c=.o}
NAME	=	push_swap
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -Iinc
all:	${NAME}
$(NAME):	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${DSRCS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
