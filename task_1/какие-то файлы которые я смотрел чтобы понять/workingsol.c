
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>

int main()
{

	printf("q to quit\n");
	int i = 0;
	int num=0, l = 0;
//	int maxlen = sysconf(_SC_ARG_MAX)+1;
	char* command;
  command=malloc(sizeof(char)*100);

	char** str_arg;
	char delim[]=" ,-";
	while(1)
	{

  printf("ENTER CMD OR 'q' >>>\n");

          i=0;
	        scanf("%s", command);
		l = 0;
		l = strlen(command);

if (*(command) == 'q'){ return 0;}

		num = 0;
		for(i=0;i<l;i++)
		{
			if(*(command+i)==' ' || *(command+i)==',' || *(command+i)=='-')
			{
				num++;
			}
		}

		i = 0;
		str_arg = malloc(sizeof(char*)*(num+1));
		for(char *p=strtok(command, delim); p!=NULL; p = strtok(NULL, delim))
		{
			*(str_arg+i)=p;
			i++;
		}



		pid_t pid = fork();
		if(pid<0)
		{
			printf("fork error\n");
			return -1;
		}
		if(pid)
		{
			int status;
			waitpid(pid, &status, 0);
			printf("Ret code: %d\n", WEXITSTATUS(status));
		}
		else
		{
      if (!strcmp(str_arg[0], "cd")){
      execl("/bin/sh", "-c", str_arg[0], str_arg , (const char *)0);
}


    	execvp(str_arg[0],str_arg);
		}

		free(str_arg);
		free(command);
	}
	return 0;
}
