#include "../includes/minishell.h"

void    copy_env(char **env)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	g_info.env = (char **)malloc(sizeof(char *) * (count + 1));
	while (env[i])
	{
		g_info.env[i] = ft_strdup(env[i]);
		i++;
	}
	g_info.env[i] = NULL;    
}