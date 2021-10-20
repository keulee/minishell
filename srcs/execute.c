#include "../includes/minishell.h"

void	execute_cmds(t_node *node)
{
	pid_t	pid;
	// t_node	*tmp;

	// tmp = node;
	pid = fork();
	if (pid < 0)
		return ;
	g_info.fork_flag = 1;
	// printf("pid : %d\n", pid);
	if (pid == 0)
	{
 		if (node->type == BUILTIN_CMD)
 			ft_built_in(node);
		if (node->type == CMD)
		{
	// 	// exec
			ft_execmd(node);
			return ;
		}
		// if (node->next && node->type != CMD)
		// {
		// 	if(node->next->type == PIPE)
		// 		exit(EXIT_SUCCESS);
		// 	node = node->next;
		// }
			
	}
	else
		exit(EXIT_SUCCESS);
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

// void	ft_exec(t_cmd **cmd)
void	ft_exec(t_node *node)
{
	// t_node	*tmp;
	// int		status;
		// int i = 0;
	
	// tmp = (*cmd)->cmd_start;
	// if (!tmp)
		// return ;

	// g_info.fork_flag = 0;
	// init_befor_exec(tmp);
	init_befor_exec(node);
	// printf("how many pipe : %d\n", g_info.count_pipe);
	while (node)
	{
 		if (node->type == BUILTIN_CMD)
 			ft_built_in(node);
		// execute_cmds(node);
		if (node->type == CMD)
		// 	// exec
			ft_execmd(node);
		// tmp = tmp->next;
		if (node->next && node->type != PIPE)
				node = node->next;
		node = node->next;
	}
	// if (g_info.fork_flag)
	// {
	// 	while (waitpid(-1, &status, 0) > 0)
	// 	{
	// 		printf("waiting\n");
	// 		if(WIFEXITED(status) == 0)
	// 			g_info.exit_code = WEXITSTATUS(status);
	// 	}
	// }
}