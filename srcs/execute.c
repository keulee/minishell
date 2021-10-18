#include "../includes/minishell.h"

void	ft_exec(t_cmd **cmd)
{
	t_node *tmp;

	tmp = (*cmd)->cmd_start;
	if (!tmp)
		return ;
	while (tmp)
	{
		// if (tmp->type == BUILTIN_CMD)
			// bti 
		if (tmp->type == CMD)
			// exec
			ft_execmd(tmp);
		tmp = tmp->next;
	}
}