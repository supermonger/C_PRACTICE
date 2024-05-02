#include <stdio.h>

int rev_num(int num) {
    int sum = 0;
    while (num) {
        sum = 10*sum + (num%10);
        num /= 10;
    }
    return sum;
}

int main() {
    int a = 123456;
    printf("%d reverse to %d\n", a, rev_num(a));
    return 0;
}