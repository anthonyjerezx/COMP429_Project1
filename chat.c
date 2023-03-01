#include "server.h"
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#define SERVER_ADDR "172.217.160.99"
#define SERVER_PORT 80

int port;

void *server_func(void *arg){
    printf("server func ran \n");
}

int main(int argc, char const *argv[])
{
    char cmd[16];
    /* handle port assignment from cmdline */
    if (argc < 2)
    {
        port = 8080;
    }
    else
    {
        port = atoi(argv[1]);
    }

    /* create thread for server/socket on the machine to listen */
    pthread_t server_thread; 
    int iret = pthread_create(&server_thread, NULL, server_func, NULL);
    printf("%d \n", iret);
    pthread_join(server_thread, NULL);


    // loop for the client 
    char message[255];
    while (1)
    {
        printf(">: ");
        fgets(cmd,16,stdin);

/*      printf("cmd is: %s \n", cmd);
        printf("cmd[0] = %c \n", cmd[0]); */

        // strip the first letter from the cmd input and use it for the switch
        switch (cmd[0])
        {
        case 'h':
            printf("here is a list of commands and their usage \n");
            printf("------------------------------------------- \n");
            printf("help: displays this menu\n");
            printf("ip: shows the users ip address \n");
            printf("port: shows the current port number\n");
            printf("list: list available concections on the p2p system \n");
            printf("connect: \n");
            printf("terminate: \n");
            printf("send: \n");
            printf("exit: leave the program \n");
            printf("\n\n");
            break;
        case 'i':
            GetMyIp();
            break;
        case 'p':
            printf("you're port#: %d \n",port);
            break;
        case 'l':
            printf("list \n");
            break;
        case'c':
            printf("connect\n"); 
            break;
        case't':
            printf("Terminate \n");
            break;
        case 's':
            printf("enter your message: \n");
            //clear out the message every time
            memset(message, 0, 255);
            fgets(message, 255, stdin);
            printf("your message: %s \n ",message);
            break;
        case 'e':
            exit(0);
        default:
            printf("input not unsderstood\n");
            break;
        }
    }

    return 0;
}
