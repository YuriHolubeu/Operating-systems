
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

void SearchDirectory(const char *name) {
    DIR *dir = opendir(name);               //Assuming absolute pathname here.
    if(dir) {
        char Path[PATH_MAX], *EndPtr = Path;
        struct stat info;                //Helps us know about stuff
        struct dirent *e;
        strcpy(Path, name);                  //Copies the current path to the 'Path' variable.
        EndPtr += strlen(name);              //Moves the EndPtr to the ending position.
        while ((e = readdir(dir)) != NULL) {  //Iterates through the entire directory.
            strcpy(EndPtr, e -> d_name);       //Copies the current filename to the end of
            //the path, overwriting it with each loop.
            if (!stat(Path, &info)) {         //stat returns zero on success.
                if (S_ISDIR(info.st_mode)) {  //Are we dealing with a directory?
                    //Make corresponding directory in the target folder here.
                    printf("directory: %s/\n", Path);


          SearchDirectory(Path);   //Calls this function AGAIN, this time with the sub-name.
                } else if (S_ISREG(info.st_mode)) { //Or did we find a regular file?
                    ;
                    //Run Copy routine
                    printf("reg_file: %s\n", Path);

  if(Path[(strlen(Path)-1)]=='t' && Path[(strlen(Path)-2)]=='x' && Path[(strlen(Path)-3)]=='t'){

printf("we have a text file\n" );
char backuppath[]="/home/yura/Desktop/programs/HW_3sem/3_sem/task_6/solution/backup";

/* почему это не работает?????
char token[12];
char **cmdmas;
char **command;
cmdmas=malloc(sizeof(char*)*100);
command=malloc(sizeof(char*)*100);
command="cp";
printf("%s\n",Path );
strcpy(token, strtok(Path, "/"));
printf("%s\n",token );
int i;
while (token !="txt"){
strcpy(token, strtok(NULL, "/."));
printf("%s\n", token);
//*(cmdmas+i)=token;
//i++;
}
*/
char **cmdmas;
cmdmas=malloc(sizeof(char*)*100);
int i;
char *token = strtok (Path, "/"); //во втором параметре указаны разделители (пробел, запятая, точка)
while (token != NULL) //пока есть лексемы
{
  printf("%s\n",token );
    token = strtok (NULL, " /");
    *(cmdmas+i)=token;
    i++;

}

printf("%s\n",cmdmas[i-2] );

/*
char nameoffile[10];
printf("name of file %s\n", cmdmas[i-1]);
strcat(command, token);
strcat(command, backuppath);

int system(const char *command);

*/




}// end of differences



                }
            }
        }
    }
    return;
}

int main() {
    printf("Hello, World!\n");
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        SearchDirectory(strcat(cwd, "/"));
    }
    return 0;
}
