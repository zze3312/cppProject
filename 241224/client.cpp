#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;

void error_handling(char *message);

struct test{
    int a;
    string b;
    char msg[100] = "";
    test(int a, string b) : a(a), b(b){
        strcat(msg, to_string(a).c_str());
        strcat(msg, ",");
        strcat(msg, b.c_str());
    }
};

int main(int argc, char *argv[]) {
    int sock;
    sockaddr_in serv_addr;
    test testmsg = {1, "hello"};

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

    //클라이언트 통신
    write(sock, &testmsg.msg, sizeof(testmsg.msg));
    cout << "메세지 보냄!!" << endl;

    close(sock);

}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}