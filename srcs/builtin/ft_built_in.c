/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:31:21 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/20 15:18:40 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//void	ft_pass_arg(t_node **cmd);
//to do:
//	1. passe arg until next pipe ou redir
//	2. and check il y a arg?

void	ft_built_in(t_node	*node)
{
	if (!ft_strcmp(node->str, "echo"))
		ft_echo(node);
	else if (!ft_strcmp(node->str, "pwd"))
		ft_pwd(node);
	else if (!ft_strcmp(node->str, "cd"))
		ft_cd(node);
	else if (!ft_strcmp(node->str, "export"))
		ft_export(node);
	else if (!ft_strcmp(node->str, "unset"))
		ft_unset(node);
	else if (!ft_strcmp(node->str, "env"))
		ft_env(node);
	else if (!ft_strcmp(node->str, "exit"))
		ft_exit_builtin(node);
}
//passe all arg
