#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    sockaddr_in serv_addr;
    char message[30] = "";
    int str_len = 0;
    int idx = 0;
    int read_len = 0;

    if (argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect() error");
    }

    // read함수가 0을 반환하면 이는 거짓을 의미하므로 while을 빠져나갈 수 있음
    while (read_len = read(sock, &message[idx++], 1)) {
        if (read_len == -1) {
            error_handling("read() error");
        }

        str_len += read_len;
    }

    printf("Message from server : %s\n", message);
    printf("Function read call count : %d\n", str_len);
    close(sock);

}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}