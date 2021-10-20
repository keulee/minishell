/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:10:13 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/20 15:23:25 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_chercher_key(t_envp *envp, char *arg)
{
	t_envp	*tmp;

	if (!envp || !arg)
		return (0);
	tmp = envp->prev;
	while (envp != tmp)
	{
		if (!ft_strcmp(envp->envp_key, arg))
			return (1);
		envp = envp->next;
	}
	if (!ft_strcmp(envp->envp_key, arg))
		return (1);
	return (0);
}

void	ft_free_one_node(t_envp *envp, char *arg)
{
	while (envp)
	{
		if (!ft_strcmp((envp)->envp_key, arg))
		{
			(envp)->next->prev = (envp)->prev;
			(envp)->prev->next = (envp)->next;
			free((envp)->envp_key);
			free((envp)->envp_value);
			free((envp)->envp_str);
			free((envp));
			return ;
		}
		(envp) = (envp)->next;
	}
}

void	ft_unset(t_node *node)
{
	char	*arg;

	if (!node)
		return ;
	if (!(node->next))
	{
		ft_putstr("unset : not enough arguments\n");
		g_info.exit_code = 1;
		return ;
	}
	if (node->next->type != 12)
	{
		ft_putstr("unset : not enough arguments\n");
		g_info.exit_code = 1;
		return ;
	}
	arg = node->next->str;
	if (!ft_chercher_key(g_info.envp, arg))
		return ;
	ft_free_one_node(g_info.envp, arg);
	g_info.exit_code = 0;
}
