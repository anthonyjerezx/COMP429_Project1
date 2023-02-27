#include "server.h"
#include <stdlib.h>
#define SERVER_ADDR "172.217.160.99"
#define SERVER_PORT 80

int port; 

int main(int argc, char const *argv[])
{
    
    /* handle port assignment from cmdline */
    if (argc < 2)
    {
        port = 8080;
    }else
    {
        port = atoi(argv[1]); 
    }
    

    printf("%d", port);

    
    //GetMyIp();
    return 0;
}

