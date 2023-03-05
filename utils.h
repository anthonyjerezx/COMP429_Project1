#if !defined(UTILS_H)
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 80 
#define SERVER_ADDR "172.217.160.99"

void returnIP(char *ip);

#endif // UTILS_H