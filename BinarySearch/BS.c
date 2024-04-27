#include <stdio.h>

int BinarySearch(int* arr, int size, int val) {
    int l = 0;
    int r = size-1;
    if (arr[l] == val) return l;
    if (arr[r] == val) return r;
    while (l<r-1) {
        int m = (l+r)/2;
        if (arr[m]==val) {
            return m;
        }
        else if(arr[m]<val){
            l = m;
        }
        else {
            r = m;
        }
    }
    return -1;
}

int main(){
    int arr[15] = {1,3,5,6,7,8,12,15,16,18,19,22,23,26,30};
    int index = BinarySearch(arr, 15, 25);
    printf("%d\n", index);
    return 0;
}