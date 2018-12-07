      #include <string.h>
      #include <sys/stat.h>
      #include <sys/types.h>
      #include <netinet/in.h>
      #include <sys/time.h>
      #include <sys/socket.h>
      #include <sys/un.h>
      #include <unistd.h>
      #include <signal.h>
      #include <sys/wait.h>
      #include <resolv.h>
      #include <errno.h>
      #include <stdio.h>
      #include <limits.h>
      #include <dirent.h>
      #include <stdlib.h>


void Daemon(const char *name) {
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
                    ;
          Daemon(Path);   //Calls this function AGAIN, this time with the sub-name.
                } else if (S_ISREG(info.st_mode)) { //Or did we find a regular file?

                    //int res2;
                    //res2 = system("diff file1.txt file2.txt");
                    char s;
                    const char *file ="file";
                    //s = system("file e");

                    //char *args[]={EndPtr, file, e->d_name, NULL};
                    //execv(args[0],args);

                    //Run Copy routine
                    printf("reg_file: %s\n", Path);
                }
            }
        }
    }
    return;
}




int main(int argc, char* argv[])
{
int res;
 res = mkdir("backup", S_IRUSR|S_IRGRP|S_IROTH|S_IXUSR);
  char cwd[PATH_MAX];

pid_t parpid;

if((parpid=fork())<0)
{
   printf("\ncan't fork\n");
  exit(1);}

else if (parpid!=0)
        exit(0);
        setsid();
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            Daemon(strcat(cwd, "foldertest/"));
        }

return 0;
}
