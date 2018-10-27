#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

char *original;
char *token;
  int status;
char **cmdmas;

  while(1) {


cmdmas=malloc(sizeof(char*)*100);
original = malloc(sizeof(char)*100);

printf("ENTER CMD OR 'q' >>>\n");
scanf("%[^\n]%*c", original);

if (*(original) == 'q'){ return 0;}

//original = strdup(original);


const pid_t pid = fork();


if (pid < 0) {
		printf("fork() error\n");
	}


  if (pid) {//parent
  		waitpid(pid, &status, 0);
          printf("status: %d\n", status);
          printf("Return code: %d\n", WEXITSTATUS(status));
}

if(pid<1){




token=strtok(original, " -,");
int i;
while (token !=NULL){
//printf("token: %s\n", token);
token=strtok(NULL, ",- ");

*(cmdmas+i)=token;
i++;
}

execvp(cmdmas[0],cmdmas);
printf("exec* failed\n");


}




}

  return 0;
}
