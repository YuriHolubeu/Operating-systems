#include "headers.h"

//я тут подумал, что неплохо бы на все повторяющиеся вещи функцию свою написать, но нет времени
// Function designed for chat between client and server.
void func(int sockfd)
{
  char buff[MAX];
  char buffanswer[MAX];


    int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);
        write(sockfd, "enter 123 to register:", sizeof("enter 123 to register"));
        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s", buff);

      if(strncmp(buff, "123", 3)==0){

        printf("comeone has connected!\n" );
        char buffanswer[MAX]="connected! I have files 1, 2, 3, enter GET <number>\n";
        write(sockfd, buffanswer, sizeof(buffanswer));
        bzero(buffanswer, MAX);

      for (;;) {
        // здесь настоящее взаимодействие и идет
        bzero(buff, MAX);
        n = 0;
        read(sockfd, buff, sizeof(buff));
        if ((strncmp("GET", buff, 3)==0)){
          printf("client knows how to use server\n" );


          char a = buff[(strlen(buff)-2)];
printf("%d - length %c\n",(strlen(buff)-2), a);
          switch (a) {
            case '1':
             strcpy(buffanswer,"here is file 1\n");
            write(sockfd, buffanswer, sizeof(buffanswer));
            bzero(buffanswer, MAX);
            break;

            case '2':
             strcpy(buffanswer,"here is file 2\n");
            write(sockfd, buffanswer, sizeof(buffanswer));
            bzero(buffanswer, MAX);
            break;

            case '3':
             strcpy(buffanswer,"here is file 3\n");
            write(sockfd, buffanswer, sizeof(buffanswer));
            bzero(buffanswer, MAX);
            break;

            default:
             strcpy(buffanswer,"there is not such file \n");
            write(sockfd, buffanswer, sizeof(buffanswer));
            bzero(buffanswer, MAX);

          }



        }
        else {
          char buffanswer[MAX]="Inpropper usage!!! enter GET <number>\n";
          write(sockfd, buffanswer, sizeof(buffanswer));
          bzero(buffanswer, MAX);
        }



        // это никто не будет делать, просто на всякий случай пусть будет
          if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
}

}
else{
  write(sockfd, "wrong password\n", sizeof("wrong password\n"));
}



    }
}

// Driver function
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");


          func(connfd);

    // After chatting close the socket
    close(sockfd);
}
