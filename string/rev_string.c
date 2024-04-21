#include <stdio.h>
#include <string.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_str(char* str) {
    int size = strlen(str);
    int l = 0;
    int r = size-1;
    while (l<r) {
        swap(&str[l], &str[r]);
        l++;
        r--;
    }
}

int main() {
    char str[10] = "123456789a";
    printf("%s\n", str);
    reverse_str(str);
    printf("%s\n",str);
    return 0;
}