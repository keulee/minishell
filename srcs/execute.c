#include "../includes/minishell.h"

void	execute_cmds(t_node *node)
{
	pid_t	pid;
	t_node	*tmp;

	tmp = node;
	pid = fork();
	g_info.fork_flag = 1;
	if (pid == 0)
	{	
		if (tmp->type == BUILTIN_CMD)
			;
		else if (tmp->type == CMD)
	// 	// exec
			ft_execmd(tmp);
	}
	else
	{
		
	}
}

void	ft_exec(t_cmd **cmd)
{
	t_node	*tmp;
	int		status;

	g_info.fork_flag = 0;
	tmp = (*cmd)->cmd_start;
	if (!tmp)
		return ;
	while (tmp)
	{
		// if (tmp->type == BUILTIN_CMD)
			// bti
		execute_cmds(tmp);
		// if (tmp->type == CMD)
		// 	// exec
		// 	ft_execmd(tmp);
		tmp = tmp->next;
	}
	if (g_info.fork_flag)
		wait(&status);
}