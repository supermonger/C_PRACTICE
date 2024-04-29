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

ListNode* rev_LinkedList(ListNode* head) {
    if (!head->next) return head;
    ListNode* prev = NULL;
    ListNode* cur = head;
    while (cur) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

ListNode* rev_LinkedList2(ListNode* head, int l, int r) {
    ListNode* cur = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* prev_of_subhead = NULL;
    ListNode* subhead;
    ListNode* subtail;
    int count=1;
    while (count<l) {
        if (count==l-1) prev_of_subhead = cur;
        cur = cur->next;
        count++;
    }
    subtail = cur;
    while (cur && count<=r){
        subhead = cur;
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    if (prev_of_subhead) {
        prev_of_subhead->next = subhead;
        subtail->next = next;
        return head;
    }
    else {
        subtail->next = next;
        return subhead;
    }
}

int main() {
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    ListNode* head = buildList(array, 10);
    printLinkedList(head);
    ListNode* revhead = rev_LinkedList(head);
    printLinkedList(revhead);
    ListNode* revhead2 = rev_LinkedList2(revhead, 2,6);
    printLinkedList(revhead2);
    return 0;
}


