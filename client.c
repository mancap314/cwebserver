#include "common.h"
#include "print_error.h"


int main(int argc, char const* argv[])
{
    int socket_fd = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client!";
    char buffer[1024] = { 0 };

    // 1. Create socket
    if((socket_fd = socket(DOMAIN, TYPE, PROTOCOL)) < 0){
        perror("Socket creation error\n");
        print_error();
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0){
        perror("Invalid address: address not supported\n");
        print_error();
        exit(EXIT_FAILURE);
    }

    if((client_fd = connect(socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0){
        perror("Connection failed\n");
        print_error();
        exit(EXIT_FAILURE);
    }

    send(socket_fd, hello, strlen(hello), 0);
    printf("Hello message has been sent\n");
    valread = read(socket_fd, buffer, BUFFERLEN);
    printf("buffer: %s\n", buffer);

    // Close connected socket
    close(client_fd);
    return EXIT_SUCCESS;
}
