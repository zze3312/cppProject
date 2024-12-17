#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[]){
    // 클라이언트 소켓의 파일 디스크립터를 저장할 변수
    int sock;
    // 연결할 서버의 주소정보를 담을 변수
    sockaddr_in serv_addr;
    // 수신한 메세지를 저장할 버퍼 변수
    char message[30] = "";
    // 수신한 메세지가 정상적으로 도착했는지 확인할 변수
    int str_len;

    // IP주소와 포트번호 안넘어오면 프로그램 종료
    if (argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    // 클라이언트의 소켓 생성
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    // 연결할 서버의 주소 체계
    serv_addr.sin_family = AF_INET;
    // inet_addr 함수 : 문자열 정보를 네트워크 바이트 순서의 정수로 변환해주는 함수
    // 해당 함수 성공 시 빅 에디안으로 변환된 32비트 정수값, 실패 시 INADDR_NONE(-1) 반환
    // 연결할 서버의 주소
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    // 연결할 서버의 포트
    serv_addr.sin_port = htons(atoi(argv[2]));

    // connect 함수 : 클라이언트의 연결요청 기능을 하는 함수
    // sock : 클라이언트 소켓의 파일 디스크립터
    // serv_addr : 연결요청 할 서버의 주소정보를 담은 변수의 주소값 전달
    // sizeof(serv_addr) : 두번째 파라미터 serv_addr의 변수 크기를 바이트단위로 전달
    // connect 함수 성공 시 0, 실패 시 -1을 반환함을 이용하여 connect 오류 확인
    if (connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect() error");
    }

    // read 함수 : 데이터를 입력(수신)하는 함수
    // sock : 데이터 수신대상을 나타내는 파일 디스크립터
    // message : 수신할 데이터를 저장할 버퍼의 주소
    // sizeof(message) - 1 : 수신할 최대 바이트 수(문자열의 끝을 의미하는 \0을 마지막에 붙여주어야하므로 1바이트 줄임)
    // read 함수 성공 시 수신한 바이트 수(단 파일의 끝을 만나면 0), 실패 시 -1을 반환해 줌
    str_len = read(sock, message, sizeof(message) - 1);
    // 이를 이용하여 메세지가 정상적으로 전달되었는지 확인
    if (str_len == -1) {
        error_handling("read() error");
    }

    // 전달 받은 메세지 출력
    printf("Message from server : %s\n", message);

    // client의 연결 종료
    close(sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}