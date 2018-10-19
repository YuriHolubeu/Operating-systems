#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
char **cmdmas;
int i=0;


start: ;

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




char *token;

   cmdmas=malloc(sizeof(char*)*100);
    char delim[] = " ,-/?";
    token=strtok(cmd, delim);

      while (token!=NULL){
         token = strtok(NULL, delim);
*(cmd+i)=token;
i++;

if (!strcmp(token, "cd")){
execl("/bin/sh", "-c", token, NULL);
}

execvp(cmdmas[0], cmdmas);

  }

  return 0;
}
