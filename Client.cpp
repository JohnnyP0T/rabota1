#include "Client.h"

//int Client::StartServer(string& str)
int Client::StartServer(char msg[128])
{
    char buffer[LBUF];
    //char *msg;
    //strcpy(msg, str.c_str());

    struct sockaddr_in client, server;
    int n, sock, s_len, c_len;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("CLIENT: unable to create socket.\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 1305;

    if ((connect(sock, (struct sockaddr *) &server, LEN)) < 0){
        printf("CLIENT: unable to connect.\n");
        exit(1);
    }

    if ((write(sock, msg, strlen(msg))) != strlen(msg)){
        printf("CLIENT: unable to send.\n");
        exit(1);
    }

    while((n = read(sock, buffer, LBUF)) > 0){
        printf(buffer);
        memset(buffer, 0, LBUF);
    }
    
    if(buffer == "1"){
        close(sock);
        return 1;
    }
    if (n < 0){
        printf("CLIENT: unable to recieve.\n");
        exit(1);
    }
    close(sock);
    return 0;
    exit(0);
}
