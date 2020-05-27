#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    int sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;
    int respval = 0;
    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);

    for(;;)
    {
        sock = accept(listener, NULL, NULL);
        if(sock < 0)
        {
            perror("accept");
            exit(3);
        }

        for(;;)
        {
            respval++;
            bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read <= 0) break;
            printf("Data from client \t\n-- %s --\t\n with code %d\n",buf,bytes_read);
            send(sock, "Hello", bytes_read, 0);
            printf("AMessage send... Value: %d\n",respval);
        }
        close(sock);
    }
    return 0;
}
