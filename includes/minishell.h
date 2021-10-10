#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# include "../libft/libft.h"

/*
** TYPE in s_pars
*/
# define WORD 1
# define SINQ 2
# define DOUQ 3
# define BSLA 4
# define DOLR 5
# define PIPE 6
# define SEMC 7
# define LESS 8
# define GREAT 9
# define DLESS 10
# define DGREAT 11

# define TRUE 1
# define FALSE 0

/* cmd line node */
typedef struct s_node {
	int				type;
	char 			*str;
	struct s_node	*next;
} t_node;

/* cmd struct for counting size and stocking node */
typedef struct s_cmd {
	int				size;
	struct s_node	*cmd_node;
} t_cmd;

typedef	struct s_info {
	char **env;
} t_info;

/* one global variable */
t_info	g_info;

void	ascii_logo_lol(void);

void	handler(int signum);

void	ft_exit(int exit_code);

void    copy_env(char **env);
void	ft_initial_g(void);
void	ft_initial(char **env);

int		ft_parsing(char *line, t_cmd *cmd);
int		is_quotes_pair(char *line, int *index);

void	init_cmd(t_cmd *cmd);
void	insert_node(t_node **node, int type, char *str);
int		get_listsize(t_node **node);
void	print_cmdline(t_node **node); /* tmp */





#endif