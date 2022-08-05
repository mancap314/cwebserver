#ifndef COMMON_H
#define COMMON_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>

#define DOMAIN AF_INET
#define TYPE SOCK_STREAM
#define PROTOCOL (0)
#define SHUTDOWN_HOW SHUT_RDWR


#define PORT (8080)
#define BUFFERLEN (1024)
#define BACKLOG_SIZE (10)

#endif
