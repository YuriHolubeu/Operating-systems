#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include <fcntl.h>

/*вопрос: почему-то этот код ничего не выводит, хотя вроде
как должен выводить текст из буфера, а в нем - текст из файла.

также второй вопрос, почему-то файл это не компилируется,
я не могу сообразить, почему. выдается при компиляции:
gcc quastion.c -o quas
/usr/lib/gcc/x86_64-linux-gnu/7/../../../x86_64-linux-gnu/Scrt1.o: In function `_start':
(.text+0x20): undefined reference to `main'
collect2: error: ld returned 1 exit status
*/
int main()
{
  char bufd[4096];
int fld = open("text.txt", O_RDONLY | O_APPEND);
int sized = read(fld, bufd, 10);
  printf("Parent:Send to child: %s\n", bufd);


  return 0;}
