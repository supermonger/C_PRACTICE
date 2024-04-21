#include <stdio.h>

void swap(int*a, int*b) {
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

void maxheapify(int* array, int size, int node) {
    int cur = node;
    int l_child = 2*node+1;
    int r_child = 2*node+2;
    while (1) {
        int max_child;
        if (r_child < size) {
            max_child = array[l_child] > array[r_child] ? l_child : r_child;
        }
        else if(r_child==size){
            max_child = l_child;
        }
        else {
            break;
        }

        if (array[cur] < array[max_child]){
            swap(&array[cur], &array[max_child]);
            cur = max_child;
            l_child = 2*cur+1;
            r_child = 2*cur+2;
        }
        else {
            break;
        }
    }
}

void buildmaxheap(int* array, int size) {
    for (int node = size-1; node>=0; node--) {
        maxheapify(array, size, node);
    }
}



void heapsort(int* array, int size) {
    buildmaxheap(array, size);
    for (int i=size-1; i>=0; i--) {
        swap(&array[0], &array[i]);
        maxheapify(array, i, 0);
    }

}

int main() {
    int arr[9] = {5,9,2,3,4,7,6,1,8};
    heapsort(arr, 9);
    printarr(arr, 0, 8);
    return 0;
}