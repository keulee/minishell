# functions 공부

## readline

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
char *readline(const char *str);
- 입력받은 문자열을 저장하고 그 문자열을 반환한다. 빈 줄의 경우 빈 스트링을 반환.
- 라인을 읽는 중 EOF를 만나면서 라인이 비어있다면 NULL을 리턴, 반면 EOF를 만나면서 라인에 내용이 있다면 개행(newline)으로 처리된다.
- 리턴되는 line의 경우 개행 문자가 함께하지 않음. (\n이 없다)
- 사용시 입력 받은 문자열은 힙 메모리를 사용하므로 사용이 끝났다면 메모리 할당(free)을 해줘야함.
- 컴파일 시 옵션에 readline 폴더를 반드시 추가해줘야 한다. (-lreadline)

## add_history
#include <readline/history.h>
(UNIX) int add_history(const char *line); 
(GNU LIB)void add_history(const char *line);
- add_history의 인자인 line으로 기재한 문자열은 위와 아래 방향키를 통해서 readline 함수 실행 도중에 다시 불러올 수 있다.
- return
> Unix 계열 : readline 디렉토리를 이용하는 경우에는 int 타입 반환, 함수 수행에 문제가 없다면 0을, 그렇지 않다면 -1을 반환
> GNU 라이브러리 : void 타입의 반환

## rl_clear_history (?????)
void rl_clear_history (void)
- Clear the history list by deleting all of the entries, in the same manner as the History library's clear_history() function. This differs from clear_history because it frees private data Readline saves in the history list.

## rl_on_new_line
#include <readline/readline.h>
int rl_on_new_line (void)
- Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.
- readline 디렉토리 내에서 Update 관련 함수들에게 커서가 개행 문자를 통해 다음 줄로 이동했음을 알려줄 때 이용되는 함수 (개행 문자 수행하지 않음)
- return
> 오류 시 -1, 그렇지 않다면 0을 반환

## rl_replace_line
#include <readline/readline.h>
void rl_replace_line (const char *text, int clear_undo)
- Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.
- rl_line_buffer라는 전역 변수를 이용하는 함수. rl_line_buffer은 사용자가 입력한 문자열을 별도로 유지.
- rl_replace_line 함수는 rl_line_buffer에 입력받은 내용을 text라는 문자열로 대치한다.
- clear_undo는 내부적으로 유지 중인 undo_list를 초기화 할지의 여부를 결정하는 값. clear_undo의 값이 0이면 초기화 하지 않고, 0이와의 값이면 undo_list를 초기화.

## rl_redisplay
#include <readline/readline.h>
void rl_redisplay(void);
- rl_replace_line 함수와 같이 rl_line_buffer 전역 변수를 사용.
- 사용자가 입력하여 유지 중이 rl_line_buffer 값을 프롬프트와 함께 출력함. 이 때, 프롬프터 값은 readline 함수에 str으로 준 문자열로 이용.
- 주로 시그널을 받았을 때의 상황에서 rl_redisplay를 이용.

wait3
wait4
signal
kill
getcwd
chdir
stat
lstat
fstat
unlink
opendir
readdir
closedir
isatty
ttyname
ttyslot
ioctl
getenv
tcsetattr
tcgetattr
tgetent
tgetflag
tgetnum
tgetstr
tgoto
tputs

printf, malloc, free, write, open, read, close, fork, wait, waitpid, exit, execve, dup, dup2, pipe, strerror, perror