#include "common.h"
#include "print_error.h"


int main(int argc, char const* argv[])
{
    int server_fd, new_client_socket_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFERLEN] = { 0 };
    char* hello = "Hello from server!";

    // 1. Create socket file descriptor
    if ((server_fd = socket(DOMAIN, TYPE, PROTOCOL)) == 0){
        perror("socket() failed\n");
        print_error();
        exit(EXIT_FAILURE);
    }

    // 2. Attach forcefully socket to port PORT 
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Error with setsockopt()\n");
        print_error();
        exit(EXIT_FAILURE);
    }
    address.sin_family = DOMAIN;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // 3. Bind socket
    if(bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("bind() failed\n");
        print_error();
        exit(EXIT_FAILURE);
    }

    // 4. Listen
    if(listen(server_fd, BACKLOG_SIZE) < 0){
        perror("Error with listen()\n");
        print_error();        
        exit(EXIT_FAILURE);
    }

    while(true) {
        // 5. Accept (and creating new socket this way)
        if ((new_client_socket_fd = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0){
            perror("Error in accept\n");
            print_error();
            exit(EXIT_FAILURE);
        }

        // 6. Read buffer
        valread = read(new_client_socket_fd, buffer, BUFFERLEN);
        printf("buffer: %s\n", buffer);

        // 7. Send response
        send(new_client_socket_fd, hello, strlen(hello), 0);

        // 8. Close the connected sockets
        close(new_client_socket_fd);
    }

    // 9. Shutdown the listening socket
    // should never come so for since after an infinite loop, just to know
    shutdown(server_fd, SHUTDOWN_HOW);

    return (EXIT_SUCCESS);
}
