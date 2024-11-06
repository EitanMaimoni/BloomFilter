#include "App.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include <arpa/inet.h>

void handleClient(int client_sock, App& myApp) {
    char buffer[4096];
    while (true) {
        memset(buffer, 0, sizeof(buffer)); // Clear buffer
        int read_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
        if (read_bytes > 0) {
            // Process the received data with myApp
            std::istringstream iss(buffer);
            std::string line;
            while (std::getline(iss, line)) {
                // Process each line as a separate request
                std::cout << "Server Got: " << line << std::endl;
                std::string response = myApp.processRequest(line); // Use 'line' instead of 'request'
                // Send the response back to the client
                send(client_sock, response.c_str(), response.length(), 0);
                std::cout << "Response sent to client." << std::endl;
            }
        } else if (read_bytes == 0) {
            // Connection closed by client
            std::cout << "Client disconnected." << std::endl;
            break;
        } else {
            // An error occurred
            perror("error reading from client");
            break;
        }
    }
    close(client_sock); // Close the client socket
}


int main() {
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "error creating socket" << std::endl;
        return 1;
    }

    int opt = 1;
    // Set SO_REUSEADDR to allow the local address to be reused
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        std::cerr << "setsockopt failed" << std::endl;
        close(sock);
        return 1;
    }

    sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "error binding socket" << std::endl;
        close(sock);
        return 1;
    }

    if (listen(sock, 5) < 0) {
        std::cerr << "error listening to a socket" << std::endl;
        close(sock);
        return 1;
    }

    bool initApp = false;
    App* myApp = nullptr; // Declare myApp as a pointer and initialize it to nullptr
    while (true) {
        sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr*)&client_addr, &addr_len);
        if (client_sock < 0) {
            std::cerr << "error accepting client" << std::endl;
            continue; // Skip to the next iteration
        }
        if (!initApp) {
            char buffer[4096];
            memset(buffer, 0, sizeof(buffer));
            int read_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
            if (read_bytes <= 0) {
                std::cerr << "error reading from client" << std::endl;
                close(client_sock);
                continue; // Skip to the next iteration
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
    close(sock);
    return 0;
}
