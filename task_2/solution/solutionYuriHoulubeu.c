#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include <fcntl.h>

int main()
{

      char buf[4096];
    buf[0]='\0';
    char bufc[4096];
    int size;
    int fd1[2];  // Used to store two ends of first pipe
    int fd2[2];  // Used to store two ends of second pipe

    char input_str[100];
    pid_t p;

    if (pipe(fd1)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
    if (pipe(fd2)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }

    p = fork();

    if (p < 0)
    {
        fprintf(stderr, "fork Failed" );
        return 1;
    }

    // Parent process
    else if (p > 1)
    {
        char testSTR[100];
        int fld = open("text.txt", O_RDONLY | O_APPEND);
        if(fld < 0){
                return 1;}
  	     close(fd1[0]);
         close(fd2[1]);
         while((size = read(fld, buf, sizeof(buf)-1)) > 0)
              {
                    //  buf[size] = 0;
                      write(fd1[1], buf, size);
                      printf("Parent:Send to child: %s\n", buf);

      		read(fd2[0], bufc, sizeof(bufc)-1);
      	//	bufc[size]='\0';
      		printf("Parent:Received from child: %s\n", bufc);
              }
        }
        else {
      	close(fd1[1]);
          	close(fd2[0]);

              int fld = open("text.txt", O_RDONLY | O_APPEND);
          	while((size = read(fd1[0], buf, sizeof(buf)-1)) > 0)
          	{
            	//	buf[size] = '\0'; // the text string data is expected
            		printf("Child:Received from parent: %s\n", buf);

      		read(fld, bufc, sizeof(bufc) -1);
      		//bufc[size]=0;
      		write(fd2[1], bufc, size);
      		printf("Child:Send to parent: %s\n", bufc);
          	}
        }

        return 0;
      }
