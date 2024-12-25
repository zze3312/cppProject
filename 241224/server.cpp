#include "testHeader.h"
void read_childproc(int sig);

int main(int argc, char *argv[]){
    int serv_sock; // 서버소켓의 파일디스크립터 저장 공간
    int clnt_sock; // 클라이언트소켓의 파일디스크립터 저장 공간
    int str_len, state;

    sockaddr_in serv_addr; // 서버의 소켓 주소 정보 - IPv4형식
    sockaddr_in clnt_addr; // 클라이언트의 소켓 주소 정보
    socklen_t clnt_addr_size; // 클라이언트 소켓의 길이 정보

    pid_t pid;
    struct sigaction act;
    char reqNum[BUF_SIZE] = "";

    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, NULL);

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("bind() error");
    }
    if (listen(serv_sock, 5) == -1) {
        error_handling("listen() error");
    }

    while (1) {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (sockaddr*)&clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1) {
            continue;
        }else {
            cout << "Client connected! > conn IP : " << inet_ntoa(clnt_addr.sin_addr) << endl;
        }
        pid = fork();
        if (pid == -1) {
            close(clnt_sock);
            continue;
        }
        if (pid == 0) {
            close(serv_sock);
            cout << "클라이언트의 데이터 기다리는중..." << endl;
            //서버통신
            read(clnt_sock, &reqNum, sizeof(int));
            cout << "클라이언트에게 데이터 받음 : " << reqNum << endl;

            if (!strcmp(reqNum, "q\n") || !strcmp(reqNum, "Q\n")) {
                break;
            }

            test *t = new test(1,"HImynameisjihyeon", "jihyeon222221231231");
            string buf = t->serializeData();
            buf += "^%^" + string(reqNum);

            write(clnt_sock, buf.c_str(), buf.size());
            shutdown(clnt_sock, SHUT_WR);
            cout << "클라이언트에게 데이터 보냄 : " << buf << endl;
            delete t;
        }else {
            close(clnt_sock);
        }
    }
    close(serv_sock);
    cout << "서버 끝!" << endl;

    return 0;
}

void read_childproc(int sig) {
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    cout << "remove proc id : " << pid << endl;
}