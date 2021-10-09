#include "../includes/minishell.h"

int ft_parsing(char *line, t_cmd *cmd)
{
	int i;

	i = 0;
	(void)cmd;
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
		else
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