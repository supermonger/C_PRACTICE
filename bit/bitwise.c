#include <stdio.h>

// Q1
int modify_nbit(int num, int n) {
    return (num | (1<<n));
}
// Q2
int power_of_2(int num) {
    return (num&(num-1)==0)&&(num!=0);
}
// Q3
int clear_nbit(int num, int n) {
    return (num & ~(1<<n));
}
// Q4 Count 1 bit
int count_1bit(int num) {
    int count=0;
    while (num) {
        num = num&(num-1);
        count++;
    }
    return count;
}
// Q5 write a code that check the input is a multiple of 3 or not without using division or mod
int check_3x(unsigned int num) {
    /*set num = abcde
      =abc*4 + de = abc*3 + (abc + de)
    */
   if (num==0 || num==3) return 1;
   else if (num==1 || num==2) return 0;
   num = (num>>2) + (num&3);
   return check_3x(num);
}



int main() {
    // Q1 modify n bit
    int a = 4;
    printf("%d\n", modify_nbit(a, 5));
    // Q2 check power of 2
    int b = 65;
    printf("%d\n", power_of_2(b));
    // Q3 clear n bit
    int c = 36;
    printf("%d\n", clear_nbit(c, 5));
    // Q4 count 1 bit
    int d = 0xFFFFFFFF;
    printf("%d\n", count_1bit(d));
    // Q5 check 3x
    int e = 3*25;
    printf("%d\n", check_3x(e));
    
    return 0;
}