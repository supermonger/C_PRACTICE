#include <stdio.h>
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void printarr(int* arr, int l, int r) {
    for (int i=l; i<=r; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void subsort(int* array, int l, int r) {
    if (l<=r) {
        int ref = array[(l+r)/2];
        int i = l;
        int j = r;
        while (i<j) {
            while (array[i] < ref && i<j) {
                i++;
            };
            while (array[j] > ref && i<j) {
                j--;
            };
            // printf("ref=%d,l=%d,r=%d,i=%d,j=%d\n", ref,l,r,i,j);
            if (i>=j) break;
            swap(&array[i], &array[j]);
            // printarr(array, l, r);
        }
        subsort(array, l, i-1);
        subsort(array, i+1, r);
    }
}

void quicksort(int* array, int size) {
    subsort(array, 0, size-1);
}

int main() {
    int size = 15;
    int arr[] = {9,8,2,5,6,4,7,10,20,3,88,220,56,0,33};
    quicksort(arr, size);
    printarr(arr, 0, size-1);
    return 0;
}
