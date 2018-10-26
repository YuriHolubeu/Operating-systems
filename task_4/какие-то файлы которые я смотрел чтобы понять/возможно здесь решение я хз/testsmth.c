#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/shm.h>
#include <stdlib.h>

int main ()
{

int x, i;

for(i=1; 1<10; i++){
x=rand_r()%(11);

printf("%d\n", &x );
}

return 0;
}
