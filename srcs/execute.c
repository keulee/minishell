#include "../includes/minishell.h"

void		exec_child(t_node *node, t_node *next_cmd)//, int fd[2])
{
	if (g_info.flag_pipe)
	{
		dup2(next_cmd->fd[1], STDOUT_FILENO);
		close(next_cmd->fd[1]);
	}
	if (node->fd[0] != 0)
	{
		dup2(node->fd[0], STDIN_FILENO);
		close(node->fd[0]);
	}
	if (is_builtin(node->str))
		ft_built_in(&node);
	else
		ft_execmd_child(node);
	exit(EXIT_SUCCESS);
}

int		execute_cmds(t_node *node)// int *in, int *out)
{
	int		status;
	t_node	*next_cmd;

	next_cmd = node->next;
	while (next_cmd)
	{
		if (next_cmd->type == CMD || next_cmd->type == BUILTIN_CMD)
			break ;
		if (next_cmd->next)
			next_cmd = next_cmd->next;
		else
			break ;
	}
	if (g_info.flag_pipe)
		pipe(next_cmd->fd);
	g_info.pid_child = fork();
	if (g_info.pid_child == 0)
		exec_child(node, next_cmd);
	else if (g_info.pid_child > 0)
	{
		waitpid(g_info.pid_child, &status, 0);
		g_info.pid_child = 0;
	}
	else if (g_info.pid_child < 0)
		return (-1);
	if (g_info.flag_pipe)
		close(next_cmd->fd[1]);
	if (node->fd[0] != 0)
		close(node->fd[0]);
	return (EXIT_SUCCESS);
}

void	init_before_exec(t_node *node)
{
	t_node *tmp;

	tmp = node;
	g_info.flag_pipe = 0;
	while (node)
	{
		if (node->type == PIPE)
			g_info.flag_pipe++;
		if (node->next)
			node = node->next;
		else
			break ;
	}
}

void	ft_exec(t_node *node)
{
	if (!node)
	 	return ;
	init_before_exec(node);
	while (node)
	{
		/* redirection check - exist ?
		redirection
		*/
		/* builtin ? && no pipe ?
		builtin execute
		*/
		if (node->type == BUILTIN_CMD && !g_info.flag_pipe)
			ft_built_in(&node);
		/* else
		pipe execute
		*/
		else
			execute_cmds(node);//, &in, &out);
		if (g_info.flag_pipe)
			g_info.flag_pipe--;
		while (node->next && node->type != PIPE)
				node = node->next;
		if (node->next)
			node = node->next;
		else
			break ;
	}
}



