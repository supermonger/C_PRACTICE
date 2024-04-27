#include <stdio.h>

/*Q1 There is a sorted array “a” defined in below:
unsigned int a[1000] = {1,1,1,…,0,0,0} and a[X] >= a[X+1]
Please write a function with minimum CPU and memory resources 
to find out the X with the first 0 in this array.
*/
unsigned int findX(unsigned int* arr, int size) {
    int middle;
    int l = 0;
    int r = size-1;
    while (l!=r) {
        middle = (l+r)/2;
        if (arr[middle] == 1 && arr[middle+1] == 0){
            return middle;
        }
        else if(arr[middle] == 1) {
            l = middle;
        }
        else {
            r = middle;
        }
    }
    return 0;
}


int main() {
    //Q1 findX
    int c = 670;
    unsigned int d[1000];
    for (int i=0; i<1000; i++) {
        d[i] = (i<=c);
    }
    printf("%d\n", findX(d, 1000));
    return 0;
}