#include <stdio.h>
#include <string.h>

int main()
{
       // char *p;
        char delim[] = " ,-\n";
        char s[] = "This is \n a   -string \n";
        printf("\nWhole string: %s", s);
        printf("Splitted string:\n");


char *p = strtok(s,delim);
p = strtok(NULL, delim);
                puts(p);

       // for (char *p = strtok(s,delim); p != NULL; p = strtok(NULL, delim))
        // {               puts(p);      }
        return 0;
}
