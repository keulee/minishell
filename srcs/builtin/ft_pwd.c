/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:45:04 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/20 15:24:42 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(t_node *node)
{
	char	*pwd;

	if (node->next && node->next->type == ARG)
	{
		ft_putstr("pwd : too many arguments\n");
		g_info.exit_code = 1;
		return ;
	}
	pwd = NULL;
	pwd = getenv("PWD");
	ft_putstr(pwd);
	ft_putstr("\n");
	g_info.exit_code = 0;
}
