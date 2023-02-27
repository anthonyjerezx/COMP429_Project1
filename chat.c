#include "server.h"
#include <stdlib.h>
#define SERVER_ADDR "172.217.160.99"
#define SERVER_PORT 80

int port; 

int main(int argc, char const *argv[])
{
    char cmd[16]; 
    /* handle port assignment from cmdline */
    if (argc < 2)
    {
        port = 8080;
    }else
    {
        port = atoi(argv[1]); 
    }

    /* create thread for server/socket on the machine to listen */


    while (1)
    {
        printf(">: ");
        scanf("%s", cmd);
        printf("cmd is: %s \n", cmd);
        printf("cmd[0] = %c \n", cmd[0]);
    
    //strip the first letter from the cmd input and use it for the switch
    switch (cmd[0])
    {
    case 'h':
        printf("here is a list of commands and their usage: \n");
        printf("------------------------------------------- \n");
        printf("help: displays this menu\n");
        printf("ip: shows the users ip address \n");
        printf("port: \n");
        printf("list: list available concections on the p2p system \n");
        printf("connect: \n");
        printf("terminate: \n");
        printf("send: \n");
        printf("exit \n");
        break;
    case 'm':
        printf("your ip: \n");
    case 'e':
        exit(0);
    default:
        printf("input not unsderstood\n");
        break;
    }
    }


  
    return 0;
}

