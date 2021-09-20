NAME = minishell

SRCS = testmain.c

OBJS = $(SRCS:.c=.o)

READLINE = -lreadline -L /usr/local/opt/readline/lib -I /usr/local/opt/readline/include

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(READLINE)

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re