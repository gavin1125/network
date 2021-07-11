#include "lib/common.h"

char rot13_char(char c)
{
    if ((c >= 'a' && c <= 'm') || (c >= 'A') && c <= 'M')
        return c + 13;
    else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
        return c - 13;
    else
        return c;
}

void child_run(int fd)
{
    char outbuf[MAXLINE + 1];
    size_t outbuf_used = 0;

    ssize_t result;

    while (1)
    {
        char ch;
        result = recv(fd, &ch, 1, 0);
        if (result == 0)
        {
            break;
        }
        else if (result == -1)
        {
            perror("read");
            break;
        }

        if (outbuf_used < sizeof(outbuf))
        {

            outbuf[outbuf_used++] = rot13_char(ch);
        }

        if (ch == '\n')
        {
            send(fd, outbuf, outbuf_used, 0);
            outbuf_used = 0;
            continue;
        }
    }
}

void sigchild_hanlder(int sig)
{
    while (waitpid(-1, 0, WNOHANG) > 0)
        ;
    return;
}

int main(int argc, char **argv)
{
    int listenfd = tcp_server_listen(SERV_PORT);
    signal(SIGCHLD, sigchild_hanlder);

    while (1)
    {
        struct sockaddr_storage ss;
        socklen_t slen = sizeof(ss);
        int fd = accept(listenfd, (struct sockaddr *)&ss, &slen);
        if (fd < 0)
        {
            error(1, errno, "accept failed");
        }

        if (fork() == 0)
        {
            close(listenfd);
            child_run(fd);
            exit(0);
        }
        else
        {
            close(fd);
        }
    }

    return 0;
}