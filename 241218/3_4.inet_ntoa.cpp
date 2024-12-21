#include <iostream>
#include <cstring>
#include <arpa/inet.h>

int main() {
    sockaddr_in addr1, addr2;
    char *str_ptr;
    char str_arr[20];

    addr1.sin_addr.s_addr = htonl(0x1020304);
    addr2.sin_addr.s_addr = htonl(0x1010101);

    str_ptr = inet_ntoa(addr1.sin_addr);
    strcpy(str_arr, str_ptr);
    printf("Dotted-Decimal notation1 : %s\n", str_ptr);

    inet_ntoa(addr2.sin_addr);
    printf("Dotted-Decimal notation2 : %s\n", str_ptr);

    // line 14에서 복사해 두었으므로 이전 값 사용 가능
    printf("Dotted-Decimal notation3 : %s\n", str_arr);
    return 0;

}