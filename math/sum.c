#include <stdio.h>

// 1+2+3+...+n
int sumofn(int n) {
    return n*(n+1)/2;
}

// 1*2 + 2*3 + 3*4 + ... + (n-1)*n
//  n-1
// sigma i*(i+1)
//  i=1
int sumofn_1n(int n) {
    return (n-1)*n*(2*(n-1)+1)/6 + (n-1)*n/2;
}

int main() {
    printf("%d\n", sumofn(100));
    printf("%d\n", sumofn_1n(4));
    return 0;
}