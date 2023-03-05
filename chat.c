#include "server.h"
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#include "utils.h"

#define MESSAGE_LEN 256 

int port;
char cmd[16];
int sock;
int peers_fds[10];

struct sockaddr_in mySockaddr;
pthread_mutex_t io_lock, stdin_lock;

void print_help();

void *server_func(void *arg)
{
    int *server_fd = (int *)arg;
    int peer_fd;
    socklen_t addr_size;
    struct sockaddr_storage their_addr;
    // peer ip and peer message
    char pip[32];
    char pm[MESSAGE_LEN];

    while (1)
    {
        if (listen(*server_fd, 10) < 0)
        {
            perror("falied to listen");
            pthread_cancel(pthread_self());
        }

        addr_size = sizeof their_addr;
        if (peer_fd = accept(*server_fd, (struct sockaddr *)&their_addr, (unsigned int *)sizeof &addr_size) < 0)
            perror("failed to accept");
        memset(pm, 0, MESSAGE_LEN);
        write(peer_fd,pm, MESSAGE_LEN);
        printf("%s \n",pm);    
        inet_ntop(AF_INET, &their_addr, pip, 32);
        close(peer_fd);
    }
}

void req_connect()
{
    // request connection ip
    char rcip[32];
    // request connection port number
    int rcpn;
    printf("connect\n");
    printf("enter the ip : ");
    fgets(rcip, 32, stdin);
    printf("enter the port you wish to conect on: ");
    char temp[32];
    fgets(temp, 32, stdin);
    rcpn = atoi(temp);
    printf("connect call args: %s %d", rcip, rcpn);
}

int main(int argc, char const *argv[])
{

    pthread_t server_thread;
    int iret;
    char message[255];
    int my_fd;
    char hostIP[16];
    returnIP(hostIP);
    uint32_t hip; 
    inet_pton(AF_INET, hostIP, &hip);
    printf("value of hostIP %s %ul\n", hostIP,hip);

    /* handle port assignment from cmdline */
    if (argc < 2)
    {
        port = 8080;
    }
    else
    {
        port = atoi(argv[1]);
    }

    // create a socket to listen on
    my_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (my_fd < 0)
        perror("failed to make a socket");

    mySockaddr.sin_family = AF_INET;
    mySockaddr.sin_addr.s_addr = htonl(hip);
    mySockaddr.sin_port = port;
    printf("socket generated \n");
    /* create thread for server/socket on the machine to listen */
    if (bind(my_fd, (struct sockaddr *)&mySockaddr, sizeof(mySockaddr)) < 0)
        perror("failed to bind");

    pthread_create(&server_thread, NULL, server_func, (void *)&my_fd);

    while (1)
    {
        print_help();
        printf(">: ");
        fgets(cmd, 16, stdin);
        // strip the first letter from the cmd input and use it for the switch
        switch (cmd[0])
        {
        case 'h':
            print_help();
            break;
        case 'i':
            break;
        case 'p':
            printf("you're port#: %d \n", port);
            break;
        case 'l':
            printf("list \n");
            break;
        case 'c':
            req_connect();
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
