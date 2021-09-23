#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <stdbool.h>

# include "../libft/libft.h"

# define TEXT 0
# define SPACE 1
# define SINQ 2
# define DOUQ 3
# define BSLA 4
# define DOLR 5
# define PIPE 6
# define DPIP 7
# define SEMC 8
# define DSEM 9
# define RIGHT 10
# define DRIGHT 11
# define LEFT 12

typedef struct s_pars {
	int				type;
	char 			*str;
	struct s_pars	*prev;
	struct s_pars	*next;
} t_pars;

#endif