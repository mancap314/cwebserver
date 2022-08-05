#include "print_error.h"


void print_error(){
    switch(errno){
        case EBADF:
            perror("Invalid file descriptor given\n");
            break;
        case EACCES:
            perror("Permission denied.\n");
            break;
        case EAFNOSUPPORT:
            perror("The implementation does not support the specified address family.\n");
            break;
        case EFAULT:
            perror("The  address  pointed  to by optval is not in a valid part of the process address space.\n");
            break;
        case EINVAL:
            perror("Unknown protocol, or protocol family not available.\n");
            break;
        case EMFILE:
            perror("The per-process limit on the number of open file descriptors has been reached.\n");
            break;
        case ENOBUFS:
            perror("Insufficient memory is available.\n");
            break;
        case EPROTONOSUPPORT:
            perror("The protocol type or the specified protocol is not supported within this domain.\n");
            break;
        case ENOPROTOOPT:
            perror("The option is unknown at the level indicated.\n");
            break;
        case ENOTSOCK:
            perror("The file descriptor sockfd does not refer to a socket.\n");
            break;
        case EADDRINUSE:
            perror("The port number was specified as zero in the socket address structure, but, upon attempting to bind to an ephemeral port,  it  was  determined that all port numbers in the ephemeral port range are currently in use.\n");
            break;
        case EOPNOTSUPP:
            perror("The socket is not of a type supporting listen() (not of type SOCK_STREAM).\n");
            break;
        case EAGAIN:
            perror("The socket is marked nonblocking and no connections are present to be accepted.\n");
            break;
        case ECONNABORTED:
            perror("Connection has been aborted.\n");
            break;
        case EINTR:
            perror("The system call was interrupted by a signal that was caught before a valid connection arrived\n");
            break;
       case EPROTO:
            perror("Protocol error.\n");
            break;
        case EPERM:
            perror("Firewall rules forbid connection.\n");
            break;
    }
}
