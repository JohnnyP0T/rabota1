#include "Client.h"

int Client::StartServer(char msg[128])
{
    // Объявление локалных переменных и структур данных
    char buffer[LBUF];
    struct sockaddr_in client, server;
    int n, sock, s_len, c_len;

    // Создание сокета клиента
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("CLIENT: unable to create socket.\n");
        exit(1);
    }

    // Задание адреса главного сокета сервера
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 1305;

    // Отправление запроса к серверу на создание виртуального соединения
    if ((connect(sock, (struct sockaddr *) &server, LEN)) < 0){
        printf("CLIENT: unable to connect.\n");
        exit(1);
    }

    // Отправка сообщения серверу
    if ((write(sock, msg, strlen(msg))) != strlen(msg)){
        printf("CLIENT: unable to send.\n");
        exit(1);
    }

    // Прием от сервера сигнала об успешной работе
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

    // Завершение
    close(sock);
    return 0;
    exit(0);
}
