#if !defined(SERVER_H)
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 80 
#define SERVER_ADDR "172.217.160.99"
void GetMyIp(); 

#endif // SERVER_H
