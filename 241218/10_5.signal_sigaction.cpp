#include <iostream>
#include <unistd.h>
#include <csignal>

void timeout(int sig){
    if (sig == SIGALRM) {
        puts("Time out!");
    }
    alarm(2);
}

void keycontrol(int sig) {
    if (sig == SIGINT) {
        puts("CTRL + C Pressed");
    }
}

int main() {
    int i;

    // signal(SIGALRM, timeout);
    // signal(SIGINT, keycontrol);

    struct sigaction act;
    act.sa_handler = timeout;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, 0);

    alarm(2);

    for (i = 0; i < 3; i++) {
        puts("wait...");
        sleep(100);
    }
    return 0;
}