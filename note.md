# 과제 해석 및 공부

Your shelle should
1. not interpret unclosed quotes or unspecified special characters like \ or ;.
> 닫히지 않은 따옴표나 \ 혹은 ;와 같은 특정되지 않은 특수 문자를 해석해서는 안된다.
> 해당 경우 syntax error로 처리 필요.
> unclosed quote는 bash에서 입력했을 경우 multi line command 이므로 quote를 무시하는게 아니라 구문에러로 처리.
> \ 또는 ;와 같은 특수 문자는 bash에서 single quote, double quote의 역할을 테스트 해서 구현해야 함.
> 즉, \와 ;가 어떤 위치에 오느냐에 따라 다르게 처리해야함.
> ex) echo hello ; hello
> : hello는 echo의 인자가 됨. 따라서 ;는 명령의 종료시점, 구분을 나타내는 특수문자 역할을 함. 이후 hello는 다음 명령어로 들어감.
> ex) echo "hello ; hello"
> : 이 경우에는 따옴표 안의 hello ; hello가 echo의 인지가 됨.

2. Not use more than one global variable, think about it and be ready to explain why you do it.
> 전역변수를 하나 이상 사용하지 말 것. 전역변수를 사용한다면 그 이유에 대해 생각해 보고 설명할 준비가 되어 있어야 함.

3. Show a prompt when waiting for a new command.
>  다음 새 명령어를 기다리는 동안 prompt를 띄워야 함.

4. Have a working History.
> 작업 내역을 보여줄 수 있어야 함.
> shell에 'history' 명령어를 쳤을 때, 명령어 고유 식별번호 + 사용한 명령어가 순서대로 나옴.
> 의문 : 식별번호 옆 별표는 무엇일까...

5. Search and launch the right executable (based on the PATH variable or by using relative or absolute path)
> bash 처럼 실제 실행 가능 해야 함. (PATH 변수 기반 또는 상대/절대 경로 사용)

6. It must implement the builtins:
 * echo with option -n
 * cd with only a relative or absolute path
 * pwd with no options
 * export with no options
 * unset with no options
 * env with no options or arguments
 * exit with no options
> 아래 명령어들을 bash에서 실행 가능하도록 해야 함.
> echo (-n 옵션도 함께)
> cd (절대/상대 경로로)
> pwd (다른 옵션 없이)
> export (다른 옵션 없이)
> unset (다른 옵션 없이)
> env (다른 옵션이나 다른 인자 없이)
> exit (다른 옵션 없이)

7. ’ inhibit all interpretation of a sequence of characters.
> '(작은 따옴표)는 일련의 문자에 대한 모든 해석을 금지해야 함.

8. " inhibit all interpretation of a sequence of characters except for $.
> " (큰 따옴표)는 $(달러) 기호를 제외하고 일련의 문자에 대한 모든 해석을 금지해야 함.

9. Redirections:
 * < should redirect input.
 * '>' should redirect output.
 * “<<” read input from the current source until a line containing only the delimiter is seen.
    it doesn’t need to update history!
 * “>>” should redirect output with append mode
> 리다이렉션
> < 은 인풋을, > 은 아웃풋을 리다이렉션 해야함.
> "<<"는 한정자(limiter)를 만나기 전까지 현재 소스를 기반으로 인풋을 읽어야 하고, history에는 추가하지 않음.
> ">>"는 추가 모드(append mode)로 아웃풋 리다이렉션 해야함.