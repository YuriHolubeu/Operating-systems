// inspired by https://www.youtube.com/watch?v=esXw4bdaZkc&t=331s

#include "headers.h"
#include <stings.h>

int int main(int argc, char const *argv[]) {

    int listenfd, connfd, n
    struct sockaddr_in servaddr;

    char buff [MAXLINE+1];
    char recvline[MAXLINE+1];

//1) create new cocket for receiving
if((listenfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    printf("error\n" );

//2) setting up address

bzero (&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);

 // 3) binding socket to the address, we have created
 // "this socket is gonna listen to this address"

 if((bind(listenfd, (SA*)&servaddr, sizeof(servaddr)))<0)
    printf("error 2\n" );
if((listen(listenfd, 10))<0)
    printf("error 3\n" );


  return 0;
}
