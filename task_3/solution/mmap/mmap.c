#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main() {
  	int fdin;
	struct stat statbuf;

	fdin = open("in.txt", O_RDONLY);	//open input file, file's size
  	if(fdin<0){
		  printf("can't open input\n");
		  exit(-1);
  	}
	fstat(fdin, &statbuf);
	int size = statbuf.st_size;
	printf("size=[%d]\n",size);

	void *addrin = mmap(0, size, PROT_READ, MAP_SHARED, fdin, 0);	//mmap
	close(fdin);
	printf("Mapped at %p\n", addrin);
	/*int *shared = addr;
  	printf("%c_%c\n", *shared, shared[1]);*/

	pid_t pid = fork();		//fork
	if(pid<0){
		printf("FORK FAILED\n");
	}

	if (pid>1) {

    int status;
    waitpid(pid, &status, 0);
    printf("Ret code: %d\n", WEXITSTATUS(status));

    int t2 = clock();
    printf("time = %d\n", t2);
    //printf("I'm parent and i have already done all work)\n");
	}
	else {
    		int fdout;							//create output file
		fdout = open("out.txt", O_RDWR, S_IRUSR | S_IWUSR);
		if(fdout<0){
                  printf("can't open or create output\n");
		  exit(-1);
    }



void *addrout = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0);
printf("Mapped at %p\n", addrout);

/*for (int i =0; i < size; i++){

addrout[i]= toupper(addrout[i]); //addrin[i];
}*/
    memcpy(addrout, addrin, size);		//copy from addr to addrout

		//printf("%c_%c\n", *sh, sh[1]);

		close(fdout);
		munmap(addrout, size);
    munmap(addrin,size);
		//close(fdout);
	}


	return 0;
}
