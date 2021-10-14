#include "../includes/minishell.h"

void	set_detail_type(t_cmd **cmd)
{
    t_node	*tmp;

    if (!*cmd || !(*cmd)->cmd_start)
        return ;
	tmp = (*cmd)->cmd_start;
	if (is_builtin(tmp->str))
		tmp->type = BUILTIN_CMD;
	else
		tmp->type = CMD;
	tmp = tmp->next;
	while (tmp != NULL)
	{
			if (tmp->type != PIPE)
			{
				if ((tmp->type == LEFT || tmp->type == RIGHT || tmp->type == DRIGHT) && tmp->next)
				{
					tmp->next->type = FILE;
					tmp = tmp->next;
				}
				else if (tmp->type == DLEFT && tmp->next)
				{
					tmp->next->type = LIMITER;
					tmp = tmp->next;
				}
				else if ((tmp->type == DOLR || tmp->type == DOUQ || tmp->type == SINQ))
				{
					if (tmp->next)
						tmp = tmp->next;
				}
				else
					tmp->type = ARG;
			}
			else
			{
				if (tmp->next)
				{	
					if (is_builtin(tmp->next->str))
						tmp->next->type = BUILTIN_CMD;
					else
						tmp->next->type = CMD;
					tmp = tmp->next;
				}
			}
			tmp = tmp->next;
	}
}

int	is_builtin(char *str)
{
	if (!ft_strcmp(str, "echo"))
		return (1);
	else if (!ft_strcmp(str, "pwd"))
		return (1);
	else if (!ft_strcmp(str, "export"))
		return (1);
	else if (!ft_strcmp(str, "cd"))
		return (1);
	else if (!ft_strcmp(str, "unset"))
		return (1);
	else if (!ft_strcmp(str, "env"))
		return (1);
	return (0);
}

