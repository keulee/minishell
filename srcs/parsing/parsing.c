/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:43:09 by keulee            #+#    #+#             */
/*   Updated: 2021/11/20 15:49:11 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parsing_process(char *str, t_cmd **cmd, int *i)
{
	if (str[*i] == '\"' || str[*i] == '\'')
	{
		if (parsing_quotes(str, i, cmd))
		{
			free(str);
			return (1);
		}
	}
	else if (str[*i] == ';' || str[*i] == '\\')
		return (1);
	else if (str[*i] == '<' || str[*i] == '>' || \
							str[*i] == '|' || str[*i] == '$')
	{
		if (operation_word(cmd, str, i))
		{
			free(str);
			return (1);
		}
	}
	else
		argument_word(cmd, str, i);
	return (0);
}

void	insert_nospace_flag(t_cmd **cmd)
{
	t_node	*node;

	if (!*cmd)
		return ;
	node = (*cmd)->cmd_start;
	while (node->next != NULL)
		node = node->next;
	node->flag_nospace = 1;
}

static int	count_word(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\"' && line[i + 1] == '\"')
		{
			if (line[i + 1])
				i = i + 1;
		}
		else
			count++;
		i++;
	}
	return (count);
}

void	set_export_unset_flag(char *line)
{
	int i;
	int	index;

	i = 0;
	index = 0;
	if (ft_strstr(line, "export"))
	{
		index = ft_strstr(&line[i], "export") + 1;
		if (line[index])
		{
			if (line[index + 1] == '\"' && line[index + 2] == '\"')
				g_info.export_flag = 1;
		}
	}
	index = 0;
	if (ft_strstr(&line[i], "unset"))
	{
		index = ft_strstr(&line[i], "unset") + 1;
		if (line[index])
		{
			if (line[index + 1] == '\"' && line[index + 2] == '\"')
				g_info.unset_flag = 1;
		}
	}
}

char	*remove_quote(char *line)
{
	char	*str;
	int		i;
	int		count;
	int		j;

	count = count_word(line);
	str = malloc(sizeof(char) * (count + 1));
	i = 0;
	j = 0;
	if (ft_strstr(line, "export") || ft_strstr(line, "unset"))
		set_export_unset_flag(line);
	while (line[i])
	{
		if (line[i] == '\"' && line[i + 1] == '\"')
		{
			if (line[i + 1])
				i = i + 1;
		}
		else
		{
			str[j] = line[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_parsing(char *line, t_cmd **cmd)
{
	int		i;
	char	*str;
	int		flag;

	g_info.unset_flag = 0;
	g_info.export_flag = 0;
	str = remove_quote(line);
	i = -1;
	while (str[++i])
	{
		while (str[i] == ' ')
			i++;
		if (parsing_process(str, cmd, &i) == 1)
			return (1);
		if (str[i + 1] != ' ' && str[i + 1] != '\0')
			insert_nospace_flag(cmd);
	}
	printf("export flag = %d\n", g_info.export_flag);
	printf("unset flag = %d\n", g_info.unset_flag);
	free(str);
	return (0);
}
