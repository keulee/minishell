NAME = minishell

SRCS = testmain.c

OBJS = $(SRCS:.c=.o)

LIB = /usr/local/opt/readline/lib

INCLUDE = /usr/local/opt/readline/include

COM = -lreadline -L$(LIB) -I$(INCLUDE)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

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