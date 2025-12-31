#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345

void reverse(char *str) {
    int i, len = strlen(str);
    if (str[len - 1] == '\n') len--;  // remove newline
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int server_socket, client_socket;
    char buffer[1024];

    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Server listening...\n");

    client_socket = accept(server_socket, (struct sockaddr *)&server_addr, &addr_len);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);

        if (strcmp(buffer, "exit\n") == 0)
            break;

        reverse(buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
    close(server_socket);
    return 0;
}

