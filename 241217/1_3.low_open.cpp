#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

void error_handling(char *message);

int main() {
    // open한 파일의 디스크립터를 저장할 변수
    int fd;
    // 파일에 쓸 데이터를 저장하는 버퍼 변수
    char buf[] = "Let's go!\n";

    // open함수 : 파일을 열어주는 함수
    // "data.txt" : 파일의 이름을 나타내는 문자열의 주소
    // O_CREAT | O_WRONLY | O_TRUNC : 파일의 오픈모드
    // open 함수 성공 시 파일 디스크립터, 실패 시 -1을 반환
    fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
    // 이를 이용하여 파일이 정상적으로 열렸는지 확인
    if (fd == -1) {
        error_handling("open() error");
    }

    // 할당된 파일 디스크립터 출력
    printf("file descriptor : %d\n", fd);

    // write 함수 : 파일에 데이터를 출력(전송)하는 함수
    // fd : 데이터 전송대상을 나타내는 파일 디스크립터
    // buf : 전송할 데이터가 저장된 버퍼의 주소
    // strlen(buf) : 전송할 데이터의 바이트 수
    if (write(fd, buf, strlen(buf)) == -1) {
        error_handling("write() error");
    }

    // 파일닫기
    close(fd);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}