#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#define true 1
#define false 0


typedef char bool;
typedef char byte;
typedef FILE* File;


void start_tcp_server(int port, void(*call)(int server_fd));


void start_tcp_client(const char *ip, int port, const char *message);



#endif
