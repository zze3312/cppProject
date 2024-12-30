#include <iostream>
#include <unistd.h>
#include <thread>
#define NUM_THREADS 100

void *thread_inc(void *arg);
void *thread_des(void *arg);
long long num = 0;

int main() {
    pthread_t thread_id[NUM_THREADS];
    int i;

    printf("size of long long : %d \n", sizeof(long long ));
    for (i = 0; i < NUM_THREADS; i++) {
        if (i % 2) {
            pthread_create(&thread_id[i], NULL, thread_inc, NULL);
        }else {
            pthread_create(&thread_id[i], NULL, thread_des, NULL);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    printf("result : %lld\n", num);
    return 0;
}

void *thread_inc(void *arg) {
    for (int i = 0; i < 50000000; i++) {
        num += 1;
    }
    return NULL;
}

void *thread_des(void *arg) {
    for (int i = 0; i < 50000000; i++) {
        num -= 1;
    }
    return NULL;
}