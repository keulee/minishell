/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/20 15:20:53 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd(t_node *node)
{
	char	*pwd;
	
	(void)node;
	pwd = getenv("PWD");

	printf("%s == pwd\n", pwd);
	char *new = ft_strjoin(pwd, "/Minishell");
	pwd = getenv(new);
	int	i = chdir(new);
	printf("%d, %s == pwd\n",i , pwd);
}
