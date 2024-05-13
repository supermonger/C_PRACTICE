// gcc parallel.c -lpthread -o parallel
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void add(int* count) {
    int temp = *count + 1;
    *count = temp;
}

void* work(void* index_t) {
    static int counter = 0;
    int* index = (int*)index_t;
    for (int i=0; i<5; i++) {
        add(&counter);
        printf("counter : %d thread :%d\n",counter, *index);
        sleep(1.0E-6);
    }
    return NULL;
}

int main() {
    pthread_t t[5];
    int a[5] = {1,2,3,4,5};
    for (int i=0; i<5; i++) {
        pthread_create(&t[i], NULL, work, &a[i]);
    }
    for (int i=0; i<5; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}