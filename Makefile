SRCS = args_ops.c checkers.c customsorts.c operations_1.c operations_2.c operations_3.c push_swap.c sorting_utils1.c sorting_utils2.c split_ops.c utils.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $(CFLAGS) -o push_swap $(OBJS) $(LIBFT)

$(LIBFT):
	@make -C libft

clean:
	rm -rf *.o
	@make -C libft clean

fclean: clean
	rm -rf push_swap
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re