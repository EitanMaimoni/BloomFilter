#include "App.h"
#include <iostream>
#include <sstream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

void handleClient(SOCKET client_sock, App& myApp) {
    char buffer[4096];
    while (true) {
        ZeroMemory(buffer, sizeof(buffer)); // Windows equivalent of memset
        int read_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
        if (read_bytes > 0) {
            // Process the received data with myApp
            std::istringstream iss(buffer);
            std::string line;
            while (std::getline(iss, line)) {
                // Process each line as a separate request
                std::cout << "Server Got: " << line << std::endl;
                std::string response = myApp.processRequest(line);
                // Send the response back to the client
                send(client_sock, response.c_str(), response.length(), 0);
                std::cout << "Response sent to client." << std::endl;
            }
        }
        else if (read_bytes == 0) {
            // Connection closed by client
            std::cout << "Client disconnected." << std::endl;
            break;
        }
        else {
            // An error occurred
            std::cerr << "Error reading from client: " << WSAGetLastError() << std::endl;
            break;
        }
    }
    closesocket(client_sock); // Windows equivalent of close()
}

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    const int server_port = 5555;
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Error creating socket: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Set SO_REUSEADDR
    BOOL opt = TRUE;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) == SOCKET_ERROR) {
        std::cerr << "setsockopt failed: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    sockaddr_in server_addr;
    ZeroMemory(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Error binding socket: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    if (listen(sock, 5) == SOCKET_ERROR) {
        std::cerr << "Error listening on socket: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    bool initApp = false;
    App* myApp = nullptr;
    while (true) {
        sockaddr_in client_addr;
        int addr_len = sizeof(client_addr);
        SOCKET client_sock = accept(sock, (struct sockaddr*)&client_addr, &addr_len);
        if (client_sock == INVALID_SOCKET) {
            std::cerr << "Error accepting client: " << WSAGetLastError() << std::endl;
            continue;
        }

        if (!initApp) {
            char buffer[4096];
            ZeroMemory(buffer, sizeof(buffer));
            int read_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
            if (read_bytes <= 0) {
                std::cerr << "Error reading from client: " << WSAGetLastError() << std::endl;
                closesocket(client_sock);
                continue;
            }
            std::string request(buffer);
            myApp = new App(request);
            initApp = true;
            // Send a response to the client to indicate successful initialization
            const char* response = "App initialized successfully.";
            send(client_sock, response, strlen(response), 0);
            std::cout << "App initialized successfully." << std::endl;
            std::thread(handleClient, client_sock, std::ref(*myApp)).detach();
            continue;
        }
        std::thread(handleClient, client_sock, std::ref(*myApp)).detach();
    }

    delete myApp;
    closesocket(sock);
    WSACleanup();
    return 0;
}