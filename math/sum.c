#include <stdio.h>

// 1+2+3+...+n
int sumofn(int n) {
    return n*(n+1)/2;
}

int main() {
    printf("%d\n", sumofn(100));
    return 0;
}