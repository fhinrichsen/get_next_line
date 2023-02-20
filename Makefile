NAME	=	get_next_line.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC	=		get_next_line_utils.c \
			get_next_line.c

OUT_SRC = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OUT_SRC)
	ar -rcs	$(NAME)	$(OUT_SRC)
compile: clean
	$(CC) $(CFLAGS) $(SRC) main.c get_next_line.a -g

clean:
	$(RM) $(OUT_SRC)
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
	$(RM) get_next_line.a

re: fclean compile all

.PHONY: all clean fclean re