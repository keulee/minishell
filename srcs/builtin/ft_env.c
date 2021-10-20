/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:10:53 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/20 15:21:58 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_node *node)
{
	if (node->next && node->next->type == 12)
	{
		ft_putstr("env: too many arguments\n");
		g_info.exit_code = 1;
		return ;
	}
	ft_print_env(g_info.envp);
	g_info.exit_code = 0;
}
