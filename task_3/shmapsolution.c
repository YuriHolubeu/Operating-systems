#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/mman.h> /* mmap() is defined in this header */
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
// тупо из карпова можно переписать стр 440
int main(){



  int *array;
  int shmid;
  int new =1;
  char pathname[]= "testshmp.c";
  key_t key;


  key = ftok(pathname, 0)

if((  shmid = shmget(key, 2*sizeof(int), 0666 | IPC_CREAT | IPC_EXCL))<0){
if (errno != EXIST){

exit(-1);}

else {

if((shmid = shmget(key, 2*sizeof(int), 0))<0){
exit (-1);
}

new =0;}

}


if((array=))






  return 0;
}
