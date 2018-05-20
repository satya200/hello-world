#include "client.h"

CLIENT_PACK file_pack;

int main(int argc, char **argv)
{
    int sock_fd = 0,
        ret     = 0;
    
    socklen_t len;

    if (argc < 2) {
        printf("In sufficient argument.Ex:- a.out <port no>\n");
        return -1;
    }
    struct sockaddr_in client_addr;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(-1);
    }

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(atoi(argv[1]));
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    len = sizeof(client_addr);
    printf("Sending connectiom req to server ....\n");
    len = sizeof(client_addr);
    ret = connect(sock_fd, (const struct sockaddr *)&client_addr, len);
    if (ret < 0) {
        perror("connect");
        close(sock_fd);
        exit(-1);
    } else {
        printf("client req accepted\n");
    }

    close(sock_fd);
    return 0;
}
