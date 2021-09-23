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

typedef struct s_pars {
	int				type;
	char 			*content;
	struct s_pars	*prev;
	struct s_pars	*next;
} t_pars;

#endif