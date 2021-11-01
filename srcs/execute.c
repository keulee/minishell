#include "../includes/minishell.h"

void		exec_child(t_node *node, t_node *next_cmd)//, int fd[2])
{
	if (g_info.pipe)
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
	if (g_info.pipe)
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
	if (g_info.pipe)
		close(next_cmd->fd[1]);
	if (node->fd[0] != 0)
		close(node->fd[0]);
	return (EXIT_SUCCESS);
}

// int	count_pipe(t_node *node)
// {
// 	int		count_pipe;
// 	t_node	*tmp;

// 	count_pipe = 0;
// 	tmp = node->prev;
// 	while (node && node != tmp)
// 	{
// 		if (node->type == PIPE)
// 			count_pipe++;
// 		node = node->next;
// 	}
// 	return (count_pipe);
// }

// int	count_cmd(t_node *node)
// {
// 	int		count_cmd;
// 	t_node	*tmp;

// 	count_cmd = 0;
// 	tmp = node->prev;
// 	while (node && node != tmp)
// 	{
// 		if (node->type == BUILTIN_CMD || node->type == CMD)
// 			count_cmd++;
// 		node = node->next;
// 	}
// 	return (count_cmd);
// }

// void	ft_error_message_exec(void)
// {
// 	ft_putstr("minishell: syntax error near unexpected |\n");
// }

// void	ft_exec_multi_pipe(t_node *node)
// {
// 	printf("for multi pipe\n");
// 	(void)node;
// }

// void	ft_exec_one_pipe(t_node *node)
// {
// 	// ft_check_path_exec(node);
// 	// ft_execmd_child(node);
	
// 	// ft_built_in(node);
// 	// all_free_function;
// 	// exit(0);
// 	printf("for one pipe\n");
// 	(void)node;
// }

// void	ft_exec(t_node *node)
// {
// 	if (!node)
// 		return ;
// 	printf("%d pipe = %d == cmd\n", count_pipe(node), count_cmd(node));
// 	if (count_pipe(node) && (count_cmd(node) <= (count_pipe(node))))
// 		ft_error_message_exec();
// 	else if (count_pipe(node) == 0)
// 		execute_cmds(node);
// 	else if (count_pipe(node) == 1)
// 		ft_exec_one_pipe(node);	// fork deux exec
// 	else if (count_pipe(node) > 1)
// 		ft_exec_multi_pipe(node);	// fork all
// }

/*
int	init_befor_exec(t_node *node)
{
	pipe count;
}
*/

void	init_before_exec(t_node *node)
{
	t_node *tmp;

	tmp = node;
	g_info.pipe = 0;
	g_info.fork = 0;
	while (node)
	{
		if (node->type == CMD)
			g_info.fork++;
		if (node->type == PIPE)
			g_info.pipe++;
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
		// printf("pipe : %d\n", g_info.pipe);
		// printf("fork : %d\n", g_info.fork);
		/* pipe more than cmd
		if (count_pipe(node) && (count_cmd(node) < (count_pipe(node))))
		{
			printf("count_pipe: %d\n", count_pipe(node));
			printf("count_cmd: %d\n", count_cmd(node));
			ft_error_message_exec();
		}*/
		
		// if (g_info.pipe > 1)
		// make pipe

		/* redirection check - exist ?
		redirection
		*/
		/* builtin ? && no pipe ?
		builtin execute
		*/
		if (node->type == BUILTIN_CMD && !g_info.pipe)
			ft_built_in(&node);
		/* else
		pipe execute
		*/
		else
			execute_cmds(node);//, &in, &out);
		if (g_info.pipe)
			g_info.pipe--;
		while (node->next && node->type != PIPE)
				node = node->next;
		if (node->next)
			node = node->next;
		else
			break ;
	}
}



