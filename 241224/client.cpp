#include "testHeader.h"

int main(int argc, char *argv[]) {
    int sock;
    sockaddr_in serv_addr;
    char reqNum[BUF_SIZE] = "";

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

    fputs("Input message(Q to quit) : ", stdout);
    fgets(reqNum, BUF_SIZE, stdin);
    if (!strcmp(reqNum, "q\n") || !strcmp(reqNum, "Q\n")) {
        return 0;
    }

    write(sock, &reqNum, sizeof(int));
    cout << "메세지 보냄!!" << endl;

    char msg[1024] = "";
    read(sock, &msg[idx++], BUF_SIZE);
    cout << "read_len : " << read_len << endl;

    printf("Message from server : %s\n", msg);
    cout << "메세지 받음!!" << endl;

    test t;
    t.deserializeData(msg);

    shutdown(sock, SHUT_RD);
    close(sock);
    cout << "클라이언트 끝!" << endl;

    return 0;
}
