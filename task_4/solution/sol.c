#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <string.h>
#include <time.h>

int N;          //amount of streams
pthread_t* tid;
float* res;
int current_number = 0;
int coun = 0;
sem_t* sem;
int max = 5000000;
#define BILLION 1000000000L;

void* count_points(void *arg)
{
	int i = 0;
	int k = 0;
	float integ = 0;
	int n = 0;
	float x, y, val;
	sem = sem_open("NAME",0);
	if(current_number<N){
		n = current_number;
		current_number++;
	}
	else
	{
		printf("ERROR In TREAD_STUFF\n");
		return NULL;
	}
	for(i=0;i<max/N;i++){
		x = (float)rand()*2/RAND_MAX;
		y = (float)rand()*4/RAND_MAX;
		val = x*x;
		if(y<=val){
			k++;
		}
	}
	float del = 1.0/max;
	integ = k*del*8*N;
	//printf("{%f}\n", integ);
	res[n]=integ;

//pthread_exit(0);
coun++;
	if(coun==N){
		sem_post(sem);
	}

	return NULL;
}

int main(void){
	printf("ENTER THE NUMER OF STREAMS:\n");
	scanf("%d", &N);
	tid = malloc(sizeof(pthread_t)*N);
	res = malloc(sizeof(float)*N);
	int i = 0;
	int err;

	struct timespec start, stop;
        double full_time;

	if( clock_gettime( CLOCK_MONOTONIC, &start) == -1 ) {
                perror( "clock gettime" );
                return EXIT_FAILURE;
	}

	while(i < N) {
        	err = pthread_create(&(tid[i]), NULL, &count_points, NULL);
        	if (err != 0){
       		     printf("\ncan't create thread :[%s]", strerror(err));
		}
        	else{
        printf("\n Thread %d created successfully with tid=%lu\n", i, (unsigned long)tid[i]);
		}
		i++;
	}

/*while(i < N){

	pthread_join(tid[i], NULL);
	i++;
}
*/
	sem = sem_open("NAME",O_CREAT,0776,0);
	sem_wait(sem);

//	sleep(4);
	float average_number = 0;
	for(i=0;i<N;i++){
		//printf("[%f]", res[i]);
		average_number = average_number + res[i];
	}
	average_number = average_number/N;
	printf("integrate(x^2dx),[0;2]=%f\n", average_number);

	if( clock_gettime( CLOCK_MONOTONIC, &stop) == -1 ) {
               		 perror( "clock gettime" );
        	        return EXIT_FAILURE;
	}

	full_time = ( stop.tv_sec - start.tv_sec )  + (double)( stop.tv_nsec - start.tv_nsec )
/                (double)BILLION;

	printf( "time=%lf seconds\n", full_time );
	free(res);
	free(tid);
	return 0;
}
