   #pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;
#define LEN sizeof(struct sockaddr_in)
#define LBUF 128
//char buffer[LBUF];
//char *msg = "Potlog eto my client";
class Client
{
    public:
    //int StartServer(string& str);
    int StartServer(char *msg);
};