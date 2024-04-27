#include <stdio.h>

void primeFactorize(int n) {
    while (n%2==0) {
        n>>=1;
        printf("2 ");
    }
    for (int i=3; i*i<=n; i+=2) {
        if (n%i==0) {
            n/=i;
            printf("%d ", i);
        }
    }
    if (n!=1) {
        printf("%d\n", n);
    }
}

int isPrime(int n) {
    if (n%2==0) {
        return 0;
    }
    for (int i=3; i*i<=n; i+=2) {
        if (n%i==0) {
            return 0;
        }
    }
    return 1;
}

//find prime numbers in a given range
// void printPrimeNum(int n) {
    
// }

int main() {
    primeFactorize(17);
    printf("%d\n", isPrime(170));
    return 0;
}