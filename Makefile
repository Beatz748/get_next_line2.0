SRCS	=	get_next_line.c get_next_line_utils.c main.c

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

NAME	=	get_next_line

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -g -D BUFFER_SIZE=25	$(OBJS) -o $(NAME)

%.o: %.c
	gcc -g -D BUFFER_SIZE=25 -c $< -o $@

re: fclean $(NAME)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)
