#include "../includes/minishell.h"

int ft_parsing(char *line, t_cmd **cmd)
{
	int i;

	i = -1;
	// *cmd = init_cmd();
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\"' || line[i] == '\'')
		{
			if (parsing_quotes(line, &i, cmd))
			{
				ft_putendl_fd("Parsing Error", 1); /* 임시 message */
				return (1);
			}
		}
		else if (line[i] == ';' || line[i] == '\\')
		{
			ft_putendl_fd("Parsing error", 1); /* 임시 message */
				return (1);
		}
		else if (line[i] == '<' || line[i] == '>' || line[i] == '|' || line[i] == '$')
		{
			if (operation_word(cmd, line, &i))
			{
				ft_putendl_fd("Parsing error", 1); /* 임시 message */
				return (1);
			}
		}
		else
		{
			
			continue ;
			/* parse the others*/
			// while (ft_is_letter(line[i]))
			// 	i++;
		}
	}
	return (0);
}

