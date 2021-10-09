#include "../includes/minishell.h"

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

void	print_cmdline(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		ft_putstr("type: ");
		ft_putendl_fd(tmp->cmd_node->type, 1);
		ft_putstr("str: ");
		ft_putendl_fd(tmp->cmd_node->str, 1);
		tmp = tmp->cmd_node;
	}
}