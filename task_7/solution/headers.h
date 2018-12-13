
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#include<fcntl.h>
##include <sys/time.h>


#define PORT "3490"  // the port users will be connecting to
#define MAXLINE 4096
#define BACKLOG 10     // how many pending connections queue will hold
