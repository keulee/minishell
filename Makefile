NAME = minishell

SRCS = testmain.c

HEADER = minishell.h

OBJS = $(SRCS:.c=.o)

LIBREADLIND = -lreadline -L /usr/local/opt/readline/lib

INCREADLINE = -I /usr/local/opt/readline/include

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIBREADLIND) $(OBJS) -o $(NAME) 

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .

$(OBJS): $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCREADLINE)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re