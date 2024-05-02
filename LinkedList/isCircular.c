// Write a Program to check whether a linked list is circular or not.
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;
    
}ListNode;


int isCircular(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        if(fast==slow) {
            return 1;
        }
        else {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return 0;
}

ListNode* buildLinkedList(int* arr, int size, int connect) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = arr[0];
    ListNode* cur = head;
    ListNode* con;
    for (int i=1; i<size; i++) {
        ListNode* next = (ListNode*)malloc(sizeof(ListNode));
        next->val = arr[i];
        cur->next = next;
        cur = next;
        if (connect==i) {
            con=cur;
        }
    }
    if (con) {
        cur->next = con;
    }
    return head;
}

void freeLinkedList(ListNode* head){
    ListNode* cur = head;
    while(cur) {
        ListNode* next = cur->next;
        free(cur);
        cur = next;
    }
}

int main() {
    int arr[7] = {1,5,3,6,9,8,10};
    int connect = 5;
    ListNode* head = buildLinkedList(arr, 7, connect);
    printf("%d\n", isCircular(head));
    return 0;
}