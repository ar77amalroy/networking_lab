#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 12345
#define SERVER_IP "127.0.0.1"
int main() {
    int client_socket;
    char buffer[1024];
    struct sockaddr_in server_addr;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    while (1) {
        printf("Enter string: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(client_socket, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "exit\n") == 0)
            break;
        memset(buffer, 0, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Reversed string: %s\n", buffer);
    }
    close(client_socket);
    return 0;
}
#OR

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
int main()
{
    int s, c;
    char b[1024];
    struct sockaddr_in addr;
    s = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    bind(s, (struct sockaddr*)&addr, sizeof(addr));
    listen(s, 5);
    printf("Server listening...\n");
    c = accept(s, NULL, NULL);
    while(1)
    {
        memset(b, 0, sizeof(b));
        recv(c, b, sizeof(b), 0);
        if(strcmp(b, "exit\n") == 0)
            break;
        reverse(b);
        send(c, b, strlen(b), 0);
    }
    close(c);
    close(s);
    return 0;
}
