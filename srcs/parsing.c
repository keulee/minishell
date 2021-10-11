#include "../includes/minishell.h"

int	parsing_quotes(char *line, int *index, t_cmd **cmd)
{
	int		tmp;
	char	*str;
	char	pair;

	pair = line[(*index)++];
	tmp = *index;
	if (is_quotes_pair(line, index, pair))
		return (EXIT_FAILURE);
	while (line[*index] && line[*index] != pair)
		(*index)++;
	// printf("index : %d\n", *index);
	str = ft_substr(line, tmp, *index - tmp); /* dont forget : free needed */
	// printf("str : %s\n", str);
	if (pair == '\"')
		insert_node(cmd, DOUQ, str);
	else if (pair == '\'')
		insert_node(cmd, SINQ, str);
	// printf("*index at the end of the ft parsing quoute : %d\n", *index);
	return (EXIT_SUCCESS);
}

int	is_quotes_pair(char *line, int *index, char pair)
{
	int tmp;

	tmp = *index;
	while (line[tmp])
	{
		if (line[tmp] == pair)
			return (0);
		tmp++;
	}
	return (1);
}

int ft_parsing(char *line, t_cmd **cmd)
{
	int i;

	i = -1;
	*cmd = init_cmd();
	while (line[++i])
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
			continue ;
			// while (ft_is_letter(line[i]))
			// 	i++;
		}
	}
	return (0);
}

