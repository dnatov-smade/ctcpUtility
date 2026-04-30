#ifndef UTILS_H
#define UTILS_H


int start_tcp_server(int port, void(*call)(int server_fd));


int start_tcp_client(const char *ip, int port, const char *message);

#endif
