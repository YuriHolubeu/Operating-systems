#include "headers.h"



int main(int argc, char  **argv) {


int sockfd, n;
struct sockaddr_in servaddr;
char sendline[MAXLINE];
char recvline[MAXLINE];

if (argc !=2)
  printf("usage: %s <server address>\n", argv[0] );

if ((sockfd=socket(AF_INET, SOCK_STREAM, 0))<0)
  printf("error 1\n" );

// так как мы знаем порт, куда подключаться, то
// просто вписываем его в адрес sin_addr
// ??? то есть мы адрес передавать должны?
// в чем разница порта и адреса?
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_port= htons(PORT);
 if (inet_pton(AF_INET, argv[1],&servaddr.sin_addr)<=0)
 printf("error pton\n" );


if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))<0)
printf("error connecting\n" );

while (1) {//короче тут только отправка и получение
  //sending in cycle
    bzero(&sendline, sizeof(sendline));
  scanf("%[^\n]%*c", sendline);

// most cool thing: how to send information
//sprintf(sendline, "GET / HTTP/1.1\r\n\r\n" );
if(write(sockfd,sendline,strlen(sendline))!=strlen(sendline))
printf("erroe write in socket\n" );

//now how to receive:
memset(recvline,0,MAXLINE);
while ((n=read(sockfd, recvline,MAXLINE-1))>0) {
  printf("%s\n", recvline );





  memset(recvline,0,MAXLINE);
}
if (n<0) printf("error recv\n" );



}

  return 0;
}
