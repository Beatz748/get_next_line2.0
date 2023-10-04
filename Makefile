SRCS	=	get_next_line.c get_next_line_utils.c main.c

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

NAME	=	get_next_line

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -g	$(OBJS) -o $(NAME)

%.o: %.c
	gcc -g -c $< -o $@
