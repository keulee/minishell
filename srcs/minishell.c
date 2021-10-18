#include "../includes/minishell.h"

char	*get_path(t_node *node)
{
	char	**split_path;
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	if (!node)
		return (NULL);
	if (!ft_strncmp(node->str, "/", 1))
	{
		if (access(node->str, F_OK | X_OK) == 0)
			return (node->str);
	}
	split_path = ft_split(getenv("PATH"), ':');
	while (split_path[i])
	{
		tmp1 = ft_strjoin(split_path[i], "/");
		tmp2 = ft_strjoin(tmp1, node->str);
		free(tmp1);
		if (access(tmp2, F_OK | X_OK) == 0)
		{
			free_tab2(split_path);
			return (tmp2);
		}
		free(tmp2);
		i++;
	}
	free_tab2(split_path);
	return (NULL);
}

int ft_execmd(t_node *node)
{
	/* path 얻는 함수 - malloc*/
	char *path;
	/* cmd + arg 얻는 함수 */
	char **argv;

	(void)argv;
	path = get_path(node);
	printf("path check : %s\n", path);
	// printf("cmd exec");
	return (EXIT_SUCCESS);
}

void	ft_exec(t_cmd **cmd)
{
	t_node *tmp;

	tmp = (*cmd)->cmd_start;
	if (!tmp)
		return ;
	while (tmp)
	{
		// if (tmp->type == BUILTIN_CMD)
			// bti 
		if (tmp->type == CMD)
			// exec
			ft_execmd(tmp);
		tmp = tmp->next;
	}
}


int	main(int ac, char **av, char **env)
{
	/* readline함수의 리턴값을 저장하기위해 임의로 포인터를 하나 선언한다 */
	char *line;
	t_cmd *cmd;

	/* Init before launch*/
	ft_initial(env, ac, av); /* copy env variable with malloc */
	// cmd = init_cmd();
	ascii_logo_lol();
	while(1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		line = readline("\033[38;5;41mminishell $> \033[0m");
		cmd = init_cmd();
		if (line == NULL || (ft_strcmp(line, "exit") == 0))
		{
			ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 1);
			// free_tab2(g_info.env);
			free_list(&cmd);
			free(line);
			line = NULL;
			ft_exit(1);
		}
		add_history(line); /* add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할수있다 */
		if (ft_parsing(line, &cmd))
		{
			ft_putendl_fd("Minishell: Syntax error", 1); /* 임시 message */
			/* if there's memory allocations, need to free here */
			free_list(&cmd);
			free(line);
			line = NULL;
			continue ;
		}
		/* set detail types - CMD, BUILTIN_CMD, ARG, FILE etc with parsing elements */
		set_detail_type(&cmd);
		ft_exec(&cmd);
		print_cmdline(&cmd);
		free_list(&cmd);
		free(line);
		line = NULL;
	}
	// free_tab2(g_info.env);
	return(0);
}




	// void	classify(struct dirent *ent)
// {
// 	printf("%s\t", ent->d_name);
// 	if (ent->d_type == DT_BLK)
// 		printf("Block Device\n");
// 	else if (ent->d_type == DT_CHR)
// 		printf("Character Device\n");
// 	else if (ent->d_type == DT_DIR)
// 		printf("Directory\n");
// 	else if (ent->d_type == DT_LNK)
// 		printf("Symbolic Link\n");
// 	else if (ent->d_type == DT_REG)
// 		printf("Regular File\n");
// 	else if (ent->d_type == DT_SOCK)
// 		printf("Unix Domain Socket\n");
// 	else
// 		printf("Unknown Type File\n");
// }


	// DIR *test;
	// struct dirent *file;
	// int tmp;

	// test = opendir("/Users/keulee/mygithub/minishell");
	// if (!test)
	// {
	//     write(1, "error\n", 6);
	//     return (1);
	// }
	// while (1)
	// {
	//     tmp = errno;
	//     file = readdir(test);
	//     if (!file && tmp != errno)
	//     {
	//         write(1, "error\n", 6);
	//         break;
	//     }
	//     if (!file)
	//         break;
	//     classify(file);
	// }
	// closedir(test);
	// return (0);

	
	/* 함수종료 */