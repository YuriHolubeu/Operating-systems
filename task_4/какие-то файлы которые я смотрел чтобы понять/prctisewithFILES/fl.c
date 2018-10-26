#include<stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){

FILE *fp = fopen(argc[1], "r");
struct stat sb;

if (stat(argv[1],&sb)==-1)
{perror("can't get the sixe of a file");}

srand(45)
for(int i=0; i<5000; i++){

int index = rand()%sb.st_size;
fseek(fp, index, SEEK_SET);

  /* короче, фопен и фсик -
   классика с первого курса, чтобы
   работать с файлами, сперва получаем
   указатель на файл, далее смещениями
   получаем что угодно из него
   Ы


*/

}



}
