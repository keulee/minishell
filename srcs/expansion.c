#include "../includes/minishell.h"

void	ft_expension(t_cmd **cmd)
{
	t_node *node;

	node = (*cmd)->cmd_start;
	while (node)
	{
		if (ft_strchr((node->str), '$') && node->type == DOUQ && node->type != SINQ)
			printf("expansion case\n");
		if (node->next)
			node = node->next;
		else
			break;
	}	
}