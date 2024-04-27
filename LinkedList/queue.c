#include <stdio.h>
#include <stdlib.h>
// implement queue by linkedlist

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

void printLinkedList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("null\n");
}

ListNode* front(ListNode* head){
    ListNode* cur = head;
    while(cur->next) {
        cur = cur->next;
    }
    return cur;
}

ListNode* pop(ListNode* head){
    ListNode* cur = head;
    while(cur->next) {
        if (!cur->next->next) break;
        cur = cur->next;
    }
    cur->next = NULL;
    return head;
}

ListNode* push(ListNode* head, ListNode* node) {
    node->next = head;
    return node;
}

ListNode* back(ListNode* head) {
    return head;
}

int main() {
    ListNode* q = (ListNode*)malloc(sizeof(ListNode));
    q->val = 1;
    printLinkedList(q);
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = 2;
    q = push(q, node);
    printLinkedList(q);
    q = pop(q);
    printLinkedList(q);
    return 0;
}