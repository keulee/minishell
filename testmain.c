#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

void handler(int signum)
{
    (void)signum;
    write(STDOUT_FILENO, "minishell : \n", 14);
}

void	classify(struct dirent *ent)
{
	printf("%s\t", ent->d_name);
	if (ent->d_type == DT_BLK)
		printf("Block Device\n");
	else if (ent->d_type == DT_CHR)
		printf("Character Device\n");
	else if (ent->d_type == DT_DIR)
		printf("Directory\n");
	else if (ent->d_type == DT_LNK)
		printf("Symbolic Link\n");
	else if (ent->d_type == DT_REG)
		printf("Regular File\n");
	else if (ent->d_type == DT_SOCK)
		printf("Unix Domain Socket\n");
	else
		printf("Unknown Type File\n");
}

int	main(void)
{
/* readline함수의 리턴값을 저장하기위해 임의로 포인터를 하나 선언한다 */
    // char *str;
    // int i;
    DIR *test;
    struct dirent *file;
    int tmp;

    test = opendir("/Users/keulee/mygithub/minishell");
    if (!test)
    {
        write(1, "error\n", 6);
        return (1);
    }
    while (1)
    {
        tmp = errno;
        file = readdir(test);
        if (!file && tmp != errno)
        {
            write(1, "error\n", 6);
            break;
        }
        if (!file)
            break;
        classify(file);
    }
    closedir(test);
    return (0);


//     str = NULL;
//     signal(SIGINT, handler);
// /* 무한루프를 돌리면서 readline();함수를 반복적으로 호출할 것이다 */
//     while(1)
//     {
//         /* readline함수가 호출되면 인자(prompt : )를 터미널에 출력하고 저장할 라인을 입력받는다 */
//         str = readline("minishell : ");/* read함수는 저장한 문자열의 메모리주소를 반환한다 */
//         // if (str)/* 입력이 된다면 (주소가 존재한다면) */
// 		// {
//         //     printf("%s\n", str);/* 주소안에 문자열을 출력해보자 */
// 		// 	// printf("%p\n", str);
// 		// }
//         if (str == NULL)/* str = NULL 이라면 (EOF, cntl + D)*/
//             break ;/* 반복문을 탈출해준다.*/
//         if (strcmp(str, "exit") == 0)
//             break ;
// 	/* add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할수있다 */
//         i = add_history(str);
//         // printf("return of add_history : %d\n", i);
// 	/* 라인은 힙메모리에 저장되기때문에 다 사용한 메모리는 할당을 해제해줘야한다 */
//         free(str);
//         str = NULL;
//     }

    
    /* 함수종료 */
    return(0);
}