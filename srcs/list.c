#include "../includes/minishell.h"

void	init_cmd(t_cmd *cmd)
{
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return ;
	cmd->size = 0;
	cmd->cmd_node = NULL;
}

void	insert_node(t_node **node, int type, char *str)
{
	t_node *new;
	t_node *tmp;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_putendl_fd("Minishell: Malloc error", 1);
	tmp = *node;
	new->next = NULL;
	new->str = str;
	new->type = type;
	if (tmp == NULL)
		*node = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		get_listsize(t_node **node)
{
	t_node	*tmp;
	int		size;

	tmp = *node;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	print_cmdline(t_node **node)
{
	t_node *tmp;

	tmp = *node;
	while (tmp)
	{
		printf("type: %d\n", tmp->type);
		printf("str: %s\n", tmp->str);
		tmp = tmp->next;
	}
}