#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
    int fd1, fd2, fd3;
    // IPv4 방식의 연결지향형 소켓을 생성(TCP)
    fd1 = socket(PF_INET, SOCK_STREAM, 0);
    // test.bat 파일을 없으면 생성, 기존내용은 삭제, 쓰기전용으로 파일을 엶
    fd2 = open("test.bat", O_CREAT | O_WRONLY | O_TRUNC);
    // IPv4 방식의 비 연결지향형 소켓을 생성(UDP)
    fd3 = socket(PF_INET, SOCK_DGRAM, 0);

    // 파일 디스크립터는 3, 4, 5가 출력됨 → 0, 1, 2 는 표준 입력, 출력, 에러에 할당되어 있기 때문에 3부터 할당함
    printf("file descriptor 1 : %d\n", fd1);
    printf("file descriptor 2 : %d\n", fd2);
    printf("file descriptor 3 : %d\n", fd3);

    close(fd1); close(fd2); close(fd3);
    return 0;
}