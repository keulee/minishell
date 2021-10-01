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

# define ARG 0
# define CMD 1
# define SPCE 2
# define SINQ 3
# define DOUQ 4
# define BSLA 5
# define DOLR 6
# define PIPE 7
# define DPIP 8
# define SEMC 9
# define DSEM 10
# define RIGHT 11
# define DRIGHT 12
# define LEFT 13

# define TRUE 1
# define FALSE 0

typedef struct s_pars {
	int				type;
	char 			*str;
	struct s_pars	*next;
} t_pars;

typedef	struct s_info {
	char **env;
} t_info;

/* one global variable */
t_info	g_info;

#endif