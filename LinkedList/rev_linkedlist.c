#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode ListNode;

typedef struct ListNode
{
    int val;
    ListNode* next;
} ListNode;

ListNode* buildList(int* arr, int size) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = arr[0];
    ListNode* cur = head;
    for (int i=1; i<size; i++) {
        ListNode* next = (ListNode*)malloc(sizeof(ListNode));
        next->val = arr[i];
        cur->next = next;
        cur = next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("null\n");
}

// ListNode* rev_LinkedList(ListNode* head) {
    
// }

int main() {
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    ListNode* head = buildList(array, 10);
    printLinkedList(head);
    return 0;
}


