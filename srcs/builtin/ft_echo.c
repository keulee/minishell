/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/20 15:21:45 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_option(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i])
		if (str[i++] != 'n')
			return (0);
	return (1);
}

void	ft_echo_type_3(t_node *node)
{
	if (node->next)
		node = node->next;
	if (node->type == 12)
	{
		if (!ft_strcmp(node->str, "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else
		{
			if (ft_getenv(g_info.envp, node->str))
				ft_putstr(ft_getenv(g_info.envp, node->str));
		}
	}
}

void	ft_echo_type_2(t_node *node)
{
	if ((node->str)[0] == '$')
	{
		if (!ft_strcmp(node->str + 1, "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else
		{
			if (ft_getenv(g_info.envp, node->str + 1))
				ft_putstr(ft_getenv(g_info.envp, node->str + 1));
		}
	}
	else
		ft_putstr(node->str);
}

void	ft_print_echo(t_node *node)
{
	int	flag_space;

	flag_space = 1;
	while (node)
	{
		if (!node->next)
			flag_space = 0;
		if (node->type == 3)
			ft_echo_type_3(node);
		else if (node->type == 2)
			ft_echo_type_2(node);
		else
			ft_putstr(node->str);
		if (flag_space)
			ft_putstr(" ");
		if (node->next)
			node = node->next;
		else
			return ;
	}
}

void	ft_echo(t_node *node)
{
	int	flag_option;

	flag_option = 0;
	if (node)
		return ;
	if (!(node->next))
		return ;
	node = node->next;
	if (ft_check_option(node->str))
	{
		flag_option = 1;
		if (node->next)
			node = node->next;
	}
	ft_print_echo(node);
	if (!flag_option)
		ft_putstr("\n");
	g_info.exit_code = 0;
}
