#include "../includes/minishell.h"

///////////////함수에서 leak이 날 것만 같은데... 확인 좀 해줄 수 있겠니.../////////
char	*replace_expansion(char *exp, char *rest, int *flag)
{
	char	*tmp;
	char	*tmp2;

	if (ft_getenv(g_info.envp, exp))
		tmp = ft_strjoin(ft_getenv(g_info.envp, exp), rest);
	else
	{
		tmp2 = ft_strdup("");
		tmp = ft_strjoin(tmp2, rest);
		free(tmp2);
		*flag = 1;
	}
	return (tmp);
}
//////////////////////////////////////////////////////////////////////

char	*replace_str(char *str, int *index, int *flag)
{
	char	*exp;
	char	*rest;
	char	*tmp;
	int		i;

	i = *index;
	// printf("i is ? %d\n", i);
	while (str[i] && ft_is_letter(str[i]))
		i++;
	exp = ft_substr(str, *index, i - *index);
	rest = ft_substr(str, i, ft_strlen(str));
	tmp = replace_expansion(exp, rest, flag);
	free(exp);
	free(rest);
	*index = i;
	return (tmp);
}

void	replace_expansion_in_dquote(char **str)
{
	char	*tmp;
	char	*string;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while ((*str)[i])
	{
			// printf("here\n");
		if ((*str)[i] == '$' && (*str)[i + 1] == '\0')
		{
			// printf("here\n");
			*str = ft_strcpy(*str, "$");
		}
		else if ((*str)[i] == '$')
		{
			string = ft_substr(*str, 0, i);
			i++;
			tmp = replace_str(*str, &i, &flag);
			free(*str);
			*str = ft_strjoin(string, tmp);
			free(string);
			free(tmp);
		}
		if (flag)
			break ;
		else
			i++;
	}
}

char	*replace_env(char *exp)
{
	char *tmp;

	if (ft_getenv(g_info.envp, exp))
		tmp = ft_strdup(ft_getenv(g_info.envp, exp));
	else
		tmp = ft_strdup("");
	return (tmp);
}

char	*replace_argstr(char *str)
{
	char	*exp;
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && ft_is_letter(str[i]))
		i++;
	exp = ft_substr(str, 0, i);
	tmp = replace_env(exp);
	free(exp);
	return (tmp);
}

void	ft_delnode(t_node **node)
{
	t_node *tmp;

	if (!(*node))
		return ;
	if ((*node)->next->next)
	{
		tmp = (*node)->next;
		(*node)->next = tmp->next;
		tmp->next->prev = (*node);
		free(tmp->str);
		free(tmp);
	}
	else
	{
		tmp = (*node)->next;
		(*node)->next = NULL;
		free(tmp->str);
		free(tmp);
	}
}

void	replace_expansion_as_arg(char **str, t_node **node)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '$')
		{
			tmp = replace_argstr((*node)->next->str);
			*str = ft_strdup(tmp);
		}
		if (!ft_strcmp((*str), ""))
			break ;
		else
			i++;
	}
	if ((*node)->next && (*node)->next->flag_nospace != 1)
		(*node)->flag_nospace = 0;
	ft_delnode(&(*node)); //$PATH에서 PATH부분 노드를 가지고 들어감
}

void	ft_expension(t_cmd **cmd)
{
	t_node *node;

	node = ((*cmd)->cmd_start);
	while (node)
	{
		/* ignore when cmd is echo */
		if ((node->type == BUILTIN_CMD && !ft_strcmp(node->str, "echo")))
			break ;
		/* when "$PWD" is in quote */
		if ((ft_strchr((node->str), '$') && node->type == DOUQ && node->type != SINQ))
		{
			printf("quotes case\n");
			replace_expansion_in_dquote(&node->str);
		}
		else if (node->type == DOLR && node->next && node->next->type == ARG)
			replace_expansion_as_arg(&node->str, &(node));
		if (node->next)
			node = node->next;
		else
			break;
	}	
}
