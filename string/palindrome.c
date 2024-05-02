#include <stdio.h>
#include <string.h>

// Write a program to check whether a string is a palindrome or not.
int isPalindrome(char* s) {
    int l = 0;
    int r = strlen(s) - 1;
    while (l<r) {
        if (s[l++]!=s[r--]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* input = "1234432112344321";
    char* ans = isPalindrome(input)?"true":"false";
    printf("%s\n", ans);
    return 0;
}