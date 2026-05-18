#include "utils.h"
#include <arpa/inet.h>
#if __has_include(<bits/pthread_types.h>)
    #include <bits/pthread_types.h>
#else
    #include <pthread.h>
#endif
#include <limits.h>
#include <locale.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



void *work(void *args)
{
  int client_fd = *(int *)args;
  char buff[1024];
  int n = read(client_fd, buff, sizeof(buff) - 1);
  if (n > 0)
  {
    buff[n] = '\0';
    printf("%s\n", buff);
  }

  char msg[] = "HTTP/1.1 200 OK\r\n"
               "Content-Type: text/plain\r\n"
               "Content-Length: 15\r\n"
               "\r\n"
               "send";

  write(client_fd, msg, strlen(msg));

  close(client_fd);
  puts("Closed connection");
  free(args);

  return NULL;
}

void call(int server_fd)
{
  pthread_t threads[1000];
  int counter=0;
  printf("Server start...\n");
  while (1)
  {
    int *client_fd = malloc(sizeof(int));
    *client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0)
    {
      printf("Next \n");
    }
     pthread_create(&threads[counter],NULL,work,client_fd);
     pthread_detach(threads[counter]);
     if(counter == 1000)
     {
       counter=0;
     }
  }
}

int main(void)
{
  setvbuf(stdout, NULL, _IONBF, 0);
  setlocale(LC_ALL, "");
  start_tcp_server(8080, call);
  return 0;
}
