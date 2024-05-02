# include <stdio.h>

typedef struct mystruct
{
    char a;
    int b;
    char c[3];
    /* data */
}mystruct;


int main() {
    mystruct m;
    printf("size of int is %d\n", (int)sizeof(int));
    printf("size of char is %d\n", (int)sizeof(char));
    printf("size of a is %d\n", (int)sizeof(mystruct));
    printf("address of m   is %p\n", &m);
    printf("address of m.a is %p\n", &m.a);
    printf("address of m.b is %p\n", &m.b);
    printf("address of m.c is %p\n", &m.c);
    return 0;
    /* output
        size of int is 4
        size of char is 1
        size of a is 12
        address of m   is 0x7fff14f10d8c
        address of m.a is 0x7fff14f10d8c
        address of m.b is 0x7fff14f10d90
        address of m.c is 0x7fff14f10d94
    */
}