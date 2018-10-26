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
//#include <xlocate.h>
int main(){

int fd = open ("./sometext.txt", O_RDWR, S_IRUSR | S_IWUSR);

struct stat sb;

if (fstat(fd, &sb)== -1){
perror("couldn't get size");
}

int size = sb.st_size;

char *file_in_memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
// мы передаем fd для открытия файла, тем самым ммар и начинает работать с файлом!!1

printf("printing file as an array of characters:\n" );

for (int i =0; i < size; i++){

  if((i%2)==0){
    file_in_memory[i]= toupper(file_in_memory[i]);
  }


  printf("%c", file_in_memory[i] );
}


munmap (file_in_memory, size);

  return 0;
}
