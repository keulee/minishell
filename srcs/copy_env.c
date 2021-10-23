/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:04:24 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/23 22:15:38 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_env(char **env)
{
	t_envp	*envp;

	envp = NULL;
	ft_node_list_env(&envp, env);
	g_info.envp = envp;
	g_info.env = env;
}

void	ft_initial_g(void)
{
	g_info.envp = NULL;
	g_info.last_env_str = NULL;
	g_info.env = NULL;
}

void	ft_initial(char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_initial_g();
	copy_env(env);
}
