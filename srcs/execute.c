#include "../includes/minishell.h"

void	execute_cmds(t_node *node)
{
	if (node->type == BUILTIN_CMD)
		ft_built_in(&node);
	else if (node->type == CMD)
		ft_execmd(node);
}

/*
void	init_befor_exec(t_node *node)
{
	t_node *tmp;

	tmp = node;
	g_info.fork_flag = 0;
	g_info.count_pipe = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			g_info.count_pipe++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break;
	}
}
*/

void	ft_exec(t_node *node)
{
	if (!node)
	 	return ;
	//init_befor_exec(node);
	while (node)
	{
		execute_cmds(node);
		if (node->next && node->type != PIPE)
				node = node->next;
		if (node->next)
			node = node->next;
		else
			break ;
	}
}
