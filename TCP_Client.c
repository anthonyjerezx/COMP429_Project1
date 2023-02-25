#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    // ----- CREATING THE CLIENT -----
    // create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8989);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1) {
        printf("Connection Failed :(");
    }

    // recieve datat from server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // print the server response
    printf("Server: %s\n", server_response);

    // close the socket
    return 0;
}