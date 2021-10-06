#include "../includes/minishell.h"

/* 3 parsing groupes
** 문자그룹 : 문자, 스페이스, 싱글따옴표, 더블따옴표, 백슬래시(\), 달러
** 연산자그룹 : 파이프, 더블파이프, 세미콜론, 더블세미콜론 (더블파이프, 더블세미콜론 에러 처리 가능)
** 리다이렉션 그룹 : >, >>, <
*/

int	is_quotes_pair(char *line, int *index)
{
	char	pair;

	pair = line[*index];
	while (line[*index])
	{
		(*index)++;
		if (line[*index] == pair)
			return (0);
	}
	return (1);
}

int ft_parsing(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\"' || line[i] == '\'')
		{
			if (is_quotes_pair(line, &i))
			{
				ft_putendl_fd("Error (single quote)", 1); /* 임시 message */
				return (1);
			}
			i++;
		}
		else if (ft_is_letter(line[i]))
		{
			while (ft_is_letter(line[i]))
				i++;
		}
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	/* readline함수의 리턴값을 저장하기위해 임의로 포인터를 하나 선언한다 */
	char *line;

	/* Init before launch*/
	(void)ac;
	(void)av;
	line = NULL;
	g_info.env = NULL;
	
	/* copy env variable with malloc */
	copy_env(env);

	/* signal to manage CTL+C, CTL+D
	** need to manage CTL+/ also */
	signal(SIGINT, handler);
	while(1)
	{
		line = readline("minishell : ");
		if (line == NULL || (ft_strcmp(line, "exit") == 0))
		{
			ft_putstr_fd("minishell exit\n", 1);
			// free_tab2(g_info.env);
			exit(1);
		}
		add_history(line); /* add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할수있다 */
		/* 
		** here : parsing process with str
		*/
		if (ft_parsing(line))
		{
			ft_putendl_fd("Minishell: Syntax error", 1); /* 임시 message */
			continue ;
		}
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