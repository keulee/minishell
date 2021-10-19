#include "../includes/minishell.h"

void	execute_cmds(t_node *node)
{
	pid_t	pid;
	t_node	*tmp;

	tmp = node;
	pid = fork();
	if (pid < 0)
		return ;
	g_info.fork_flag = 1;
	printf("pid : %d\n", pid);
	if (pid == 0)
	{	
		if (tmp->type == BUILTIN_CMD)
			;
		else if (tmp->type == CMD)
	// 	// exec
			ft_execmd(tmp);
	}
	// else
		// return ;
	// return (EXIT_SUCCESS);
}

void	init_befor_exec(t_node *node)
{
	t_node *tmp;

	tmp = node;
	g_info.fork_flag = 0;
	g_info.count_pipe = 0;
	g_info.exit_code = 0;
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

void	ft_exec(t_cmd **cmd)
{
	t_node	*tmp;
	int		status;
	// int		exit_code;

	tmp = (*cmd)->cmd_start;
	if (!tmp)
		return ;
	// g_info.fork_flag = 0;
	init_befor_exec(tmp);
	printf("how many pipe : %d\n", g_info.count_pipe);
	while (tmp)
	{
		// if (tmp->type == BUILTIN_CMD)
			// bti
		execute_cmds(tmp);
		// if (tmp->type == CMD)
		// 	// exec
		// 	ft_execmd(tmp);
		if (tmp->next)
			tmp = tmp->next;
	}
	if (g_info.fork_flag)
	{
		while (waitpid(-1, &status, 0) > 0)
		{
			printf("waiting\n");
			if(WIFEXITED(status) == 0)
				g_info.exit_code = WEXITSTATUS(status);
		}
	}
}