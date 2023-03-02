#include "server.h"
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include<netinet/in.h>


int port;
char cmd[16];
struct sockaddr_in cli_addr;
int sock;
struct sockaddr_in self_addr;
struct sockaddr_in peer_list[100];

void print_help();

void *server_func(void *arg)
{
    //printf("server init \n");
    struct sockaddr_in serv_addr;
    int socketfd;
    if (socketfd = socket(AF_INET, SOCK_STREAM, 0) < 0)
    {
        perror("failed to init");
    }
    //printf("socket successfully made\n");
    
    //flushes out the server address
     bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    while (1)
    {
        sleep(5);
        printf("server running in the background\n");
    }
    
}

int main(int argc, char const *argv[])
{


    pthread_t server_thread;
    int iret;
    char message[255];


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
    
   
    if (iret = pthread_create(&server_thread, NULL, server_func, NULL) != 0)
    {
        perror("thread failed to start \n");
    }
    printf("thread succesfully made \n");
    pthread_join(server_thread, NULL);
     // print_help();
    // loop for the client
    
    while (1)
    {
        printf(">: ");
        fgets(cmd, 16, stdin);

        // strip the first letter from the cmd input and use it for the switch
        switch (cmd[0])
        {
        case 'h':
            print_help();
            break;
        case 'i':
            GetMyIp();
            break;
        case 'p':
            printf("you're port#: %d \n", port);
            break;
        case 'l':
            printf("list \n");
            break;
        case 'c':
            printf("connect\n");
            break;
        case 't':
            printf("Terminate \n");
            break;
        case 's':
            printf("enter your message: ");
            // clear out the message every time
            memset(message, 0, 255);
            fgets(message, 255, stdin);
            printf("your message: %s \n ", message);
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

void print_help()
{
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
}
