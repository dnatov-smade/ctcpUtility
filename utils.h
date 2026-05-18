#ifndef UTILS_H
#define UTILS_H


typedef void (*callback)(int server_fd);
typedef int (*response)(int sock);

int start_tcp_server(int port, callback func);



int start_tcp_request(const char *ip, int port, const char *message, int(*res)(int sock));

#endif
