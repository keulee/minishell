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
# define WORD 0
# define SPCE 1
# define SINQ 2
# define DOUQ 3
# define BSLA 4
# define DOLR 5
# define PIPE 6
# define DPIP 7
# define SEMC 8
# define DSEM 9
# define LESS 10
# define GREAT 11
# define DLESS 12
# define DGREAT 13

# define TRUE 1
# define FALSE 0

/* 3 parsing groupes
** 문자그룹 : 문자, 스페이스, 싱글따옴표, 더블따옴표, 백슬래시(\), 달러
** 연산자그룹 : 파이프, 더블파이프, 세미콜론, 더블세미콜론 (더블파이프, 더블세미콜론 에러 처리 가능)
** 리다이렉션 그룹 : >, >>, <
*/

typedef struct s_pars {
	int				type;
	char 			*str;
	struct s_pars	*next;
} t_pars;

typedef struct s_cmd {
	int				size;
	struct s_pars	*next;
} t_cmd;

typedef	struct s_info {
	char **env;
} t_info;

/* one global variable */
t_info	g_info;

void	handler(int signum);

void    copy_env(char **env);

#endif