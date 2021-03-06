#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>

size_t readn(int fd, void *vptr, size_t n);

void error(int status, int err, char *fmt, ...);

int tcp_client(char *address, int port);

int tcp_server_listen(int port);

#define SERV_PORT 43211
#define MAXLINE 4096
#define LISTENQ 1024