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
int	add_history(const char *);
- add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할 수 있다.

## rl_clear_history
void rl_clear_history (void)
- Clear the history list by deleting all of the entries, in the same manner as the History library's clear_history() function. This differs from clear_history because it frees private data Readline saves in the history list.

## rl_on_new_line
int rl_on_new_line (void)
- Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.

## rl_replace_line
void rl_replace_line (const char *text, int clear_undo)
- Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.rl_redisplay

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