#include <stdio.h>

// write a program to swap two variables without third variables

void swap(int* a, int* b){
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int main(){
    int a = 1;
    int b = 2;
    swap(&a, &b);
    printf("a is %d b is %d\n", a, b);
    return 0;
}