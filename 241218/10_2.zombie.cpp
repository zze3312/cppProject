#include <iostream>
#include <cstring>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        puts("Hi, I am a child process");
    }else {
        printf("Child process ID : %d\n", pid);
        sleep(10);
    }

    if (pid == 0) {
        puts("End child Process");
    }else {
        puts("End parent Process");
    }
    return 0;
}
