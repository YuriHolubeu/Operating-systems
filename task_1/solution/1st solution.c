#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{

printf("%d    %ld", sizeof(char), sizeof(char*));
char **cmdmas;
long unsigned int i=0;


start:
  while(1) {
    char* cmd;

    cmd=malloc(sizeof(char)*100);

printf("ENTER CMD OR 'q' >>>\n");
scanf("%s", cmd);


    if (*(cmd) == 'q'){ return 0;}




  int status;
  const pid_t pid = fork();

if (pid < 0) {
		printf("fork() error\n");
	}


if (pid) {//parent
		waitpid(pid, &status, 0);
        printf("status: %d\n", status);
        printf("Return code: %d\n", WEXITSTATUS(status));


		goto start;}


// child




// 1) преобразование
   cmdmas=malloc(sizeof(char*)*100);
    char delim[] = " ,/?";

      for (char *p = strtok(cmd,delim); p != NULL; p = strtok(NULL, delim))
 {
            *(cmdmas+i)=p;
			i++;
 }

// 2) выполнение

execvp(cmdmas[0],cmdmas);
printf("exec* failed\n");


  }
  return 0;
 }
