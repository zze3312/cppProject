#include <iostream>
#include <arpa/inet.h>

int main() {
    char *addr1 = "1.2.3.4";
    //IPv4 주소의 한칸에는 0~255까지의 값만 들어갈 수 있으므로 오류가 발생해야함
    char *addr2 = "1.2.3.256";

    unsigned long conv_addr = inet_addr(addr1);

    if (conv_addr == INADDR_NONE) {
        printf("Error occured!\n");
    }else {
        printf("Network ordered integer addr : %#lx\n", conv_addr);
    }

    conv_addr = inet_addr(addr2);
    if (conv_addr == INADDR_NONE) {
        printf("Error occured!\n");
    }else {
        printf("Network ordered integer addr : %#lx\n", conv_addr);
    }

    return 0;
}