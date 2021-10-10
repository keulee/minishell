#include "../includes/minishell.h"

int	parsing_quotes(char *line, int *index, t_cmd **cmd)
{
	int		tmp;
	char	*str;
	char	pair;

	pair = line[*index];
	printf("pair : %c\n", pair);
	tmp = *index;
	printf("index : %d\n", tmp);
	if (is_quotes_pair(line, index, pair))
		return (EXIT_FAILURE);
	printf("index : %d\n", *index);
	str = ft_substr(line, tmp, *index - tmp + 1); /* dont forget : free needed */
	printf("str : %s\n", str);
	insert_node(cmd, WORD, str);
	(*index)++;
	return (EXIT_SUCCESS);
}

int ft_parsing(char *line, t_cmd **cmd)
{
	int i;

	i = 0;
	*cmd = init_cmd();
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\"' || line[i] == '\'')
		{
			if (parsing_quotes(line, &i, cmd))
			// if (is_quotes_pair(line, &i))
			{
				ft_putendl_fd("Error", 1); /* 임시 message */
				return (1);
			}
			/* parsing string with quotes*/
		}
		else if (line[i] == ';' || line[i] == '\\')
		{
			ft_putendl_fd("Syntax error", 1); /* 임시 message */
				return (1);
		}
		else
		{
			while (ft_is_letter(line[i]))
				i++;
			i++;
		}
	}
	return (0);
}

int	is_quotes_pair(char *line, int *index, char pair)
{
	// char	pair;

	// pair = line[*index];
	while (line[*index])
	{
		(*index)++;
		if (line[*index] == pair)
			return (0);
	}
	return (1);
}