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

int ft_parsing(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\"' || line[i] == '\'')
		{
			if (is_quotes_pair(line, &i))
			{
				ft_putendl_fd("Error (single quote)", 1); /* 임시 message */
				return (1);
			}
			/* parsing string with quotes*/
			i++;
		}
		else if (line[i] == ';' || line[i] == '\\')
		{
			ft_putendl_fd("Syntax error", 1); /* 임시 message */
				return (1);
		}
		else if (ft_is_letter(line[i]))
		{
			while (ft_is_letter(line[i]))
				i++;
		}
	}
	return (0);
}

int	is_quotes_pair(char *line, int *index)
{
	char	pair;

	pair = line[*index];
	while (line[*index])
	{
		(*index)++;
		if (line[*index] == pair)
			return (0);
	}
	return (1);
}