#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// 에러 발생 시 내용 출력 후 프로그램 종료를 위한 함수
void error_handling(char *message);

int main(int argc, char *argv[]){
    int serv_sock; // 서버소켓의 파일디스크립터 저장 공간
    int clnt_sock; // 클라이언트소켓의 파일디스크립터 저장 공간

    // sockaddr_in : 소켓의 주소 타입, 주소, 포트번호가 담길 구조체
    sockaddr_in serv_addr; // 서버의 소켓 주소 정보 - IPv4형식
    // sockaddr_in6 serv_addr2; // 서버의 소켓 주소 정보 - IPv6형식
    sockaddr_in clnt_addr; // 클라이언트의 소켓 주소 정보
    socklen_t clnt_addr_size; // 클라이언트 소켓의 길이 정보

    char message[] = "Hello World!\n"; // 클라이언트에게 보낼 메세지

    // 포트정보 안넘어 오면 프로그램 종료
    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    // socket 함수 : 소켓을 생성하는 함수
    // PF_INET : IPv4 인터넷 프로토콜 체계 사용
    // SOCK_STREAM : 연결지향형 데이터 전송 소켓
    // 0 : 0으로 넣어줘도 상관없으나,
    //     하나의 프로토콜 체계 안에 데이터의 전송방식이 동일한 프로토콜이 둘 이상 존재하는 경우
    //     이 파라메터를 통하여 원하는 프로토콜의 정보를 조금더 구체화 해야함
    // socket은 성공 시 해당 소켓의 파일 디스크립터를 실패 시 -1을 반환해 줌
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);

    // 따라서 소켓 생성 실패를 확인해 준다.
    if (serv_sock == -1) {
        error_handling("socket() error");
    }

    // memset 함수 : 동일한 값으로 바이트 단위 초기화를 해줌
    // serv_addr : 초기화 할 대상
    // 0 : 초기화 할 값
    // sizeof(serv_addr) : serv_addr의 바이트 수
    // serv_addr을 모두 0으로 초기화 하는 부분 → sockaddr_in 구조체 멤버 sin_zero를 0으로 초기화 하기 위함
    memset(&serv_addr, 0, sizeof(serv_addr));

    // IPv4 인터넷 프로토콜에 적용하는 주소 체계로 셋팅
    serv_addr.sin_family = AF_INET;

    // htonl 함수 : long형 데이터를 호스트 바이트 순서에서 네트워크 바이트 순서로 변환
    // INADDR_ANY : 소켓이 동작하는 컴퓨터의 IP주소를 자동으로 할당
    // → 소켓이 동작할 컴퓨터의 IP주소 데이터를 호스트 바이트 순서에서 네트워크 바이트 순서로 변환해서 s_addr에 저장
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // htons 함수 : short형 데이터를 호스트 바이트 순서에서 네트워크 바이트 순서로 변환
    // atoi 함수 : 해당 문자열을 int형으로 반환(포트번호(argv[1])를 char[]로 가져오므로 변환해주어야 함)
    // argv[1] : 해당 프로그램을 실행할 때 전달받은 argument의 2번째 값을 가져옴(포트번호)
    serv_addr.sin_port = htons(atoi(argv[1]));

    // bind 함수 : 소켓에 인터넷 주소를 할당해주는 함수 → serv_sock에 serv_addr 주소정보를 할당해줌
    // serv_sock : 주소정보를 할당할 소켓의 파일 디스크립터
    // serv_addr : 할당하고자 하는 주소정보를 지니는 구조체 변수의 주소 값
    // sizeof(serv_addr) : 두번째 파라미터로 전달된 구조체 변수의 길이정보
    // bind 함수 실행 성공 시 0, 실패 시 -1을 반환해 주므로 이를 이용하여 bind 오류 확인
    if (bind(serv_sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("bind() error");
    }

    // listen 함수 : 연결요청 대기상태로 진입시켜주는 함수
    // serv_sock : 연결요청 대기상태로 진입시킬 대상 소켓의 파일 디스크립터
    // 5 : 연결요청 대기 큐의 크기정보(5면 큐의 크기가 5가 되며 클라이언트의 연결요청을 5개까지 대기시킬 수 있음)
    // listen 함수 실행 성공 시 0, 실패 시 -1을 반환해 주므로 이를 이용하여 listen 오류 확인
    if (listen(serv_sock, 5) == -1) {
        error_handling("listen() error");
    }

    clnt_addr_size = sizeof(clnt_addr);
    // accpet 함수 : 대기중인 클라이언트의 연결요청을 수락하는 함수
    // serv_sock : 서버소켓의 파일 디스크립터
    // clnt_addr : 연결요청 한 클라이언트의 주소정보를 담을 변수의 주소값 전달
    //             함수호출이 완료되면 인자로 전달된 주소의 변수에 클라이언트 주소정보가 채워짐
    // clnt_addr_size : 두번째 파라미터의 변수 크기를 바이트 단위로 전달
    //                  함수호출이 완료되면 크기정보로 채워져 있던 변수에는 클라이언트의 주소정보 길이가 바이트 단위로 계산되어 채워짐
    // accpet 함수 실행 성공 시 생성된 소켓의 파일 디스크립터를, 실패 시 -1을 반환해 줌
    clnt_sock = accept(serv_sock, (sockaddr*)&clnt_addr, &clnt_addr_size);
    // 이를 이용하여 accpet 오류 확인
    if (clnt_sock == -1) {
        error_handling("accept() error");
    }

    // accpet 함수 성공 시 해당 소켓으로 메세지를 전달
    // write 함수 : 파일 또는 소켓에 데이터를 출력(전송)하는 함수
    // clnt_sock : 데이터 전송대상을 가리키는 파일 디스크립터
    // message : 전송할 데이터가 저장된 버퍼의 주소
    // strlen(message) : 전송할 데이터의 바이트 수
    // write 함수 성공 시 전달한 바이트 수, 실패 시 -1 반환해 줌
    write(clnt_sock, message, strlen(message));

    // 클라이언트 접속 종료
    close(clnt_sock);
    // 서버 접속 종료
    close(serv_sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}