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

void	ft_print_echo(t_node *node)
{
	/*
	 * 모든노드 확인
	 * echo 다음에 나올 변수들
	 * 1. $ 가 나온다면 1. $? 일경우, 
	 *					2. $환경변수
	 * 2. "" 타입이 2 인 경우 , 환경변수
	 *
	 * 3. 출력에 성공했을경우 ' ' 아닐경우 무시
	 */
	while (node && node->next && node->next->type == 12)
	{
		ft_putstr(node->str);
		ft_putstr(" ");
		node = node->next;
	}
	if (node)
		ft_putstr(node->str);
}

void	ft_echo(t_node *node)
{
	int	flag_option;

	flag_option = 0;
	if (!node)
		return ;
	if (!(node->next))
	   return ;
	if (!ft_strcmp(node->next->str, "$") && !ft_strcmp(node->next->next->str, "?"))
		printf("%d",(g_info.exit_code));
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
