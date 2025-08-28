NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

d: fclean
d: CFLAGS += -g
d: $(NAME)

t: $(NAME)
	./gnl test.txt

re: fclean all

.PHONY: all clean fclean re