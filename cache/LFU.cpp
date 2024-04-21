#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct Node {
    int val;
    int key;
    int count;
    Node* next;
    Node* prev;
}Node;

// LRU linked list for each count;
typedef class LinkedList{
    public:
        int size;
        // head is least used
        Node* head;
        // tail is longest not used;
        Node* tail;
        LinkedList() {
            size=0;
        }
        void push(Node* node) {
            if (size==0) {
                head = node;
                tail = node;
            }
            else {
                node->next = head;
                head->prev = node;
                head = node;
            }
            size++;
        }
        Node* pop(Node* node) {
            if (node!=head && node!=tail) {
                Node* prevnode = node->prev;
                Node* nextnode = node->next;
                prevnode->next = nextnode;
                nextnode->prev = prevnode;
                node->prev = nullptr;
                node->next = nullptr;
            }
            else if (node!=head && node==tail) {
                Node* prevnode = node->prev;
                prevnode->next = nullptr;
                node->prev = nullptr;
                node->next = nullptr;
                tail = prevnode;
            }
            else if (node==head && node!=tail) {
                Node* nextnode = node->next;
                nextnode->prev = nullptr;
                node->next = nullptr;
                node->prev = nullptr;
                head = nextnode;
            }
            else {
                head = nullptr;
                tail = nullptr;
                node->prev = nullptr;
                node->next = nullptr;
            }
            size--;
            return node;
        }
}LinkedList;


class LFUCache {
public:
    int size;
    int cap;
    int mincount;
    // Key-Node map
    unordered_map<int, Node*> KNmap;
    // Count-Linked List map
    unordered_map<int, LinkedList*> CLmap;
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        mincount = 0;
    }
    
    int get(int key) {
        if (KNmap.count(key) == 1) {
            int count = KNmap[key]->count;
            if (count == mincount && CLmap[count]->size == 1) {
                mincount++;
            }
            Node* node = CLmap[count]->pop(KNmap[key]);
            if (CLmap.count(count+1) == 1) {
                CLmap[count+1]->push(node);
                node->count++;
            }
            else {
                LinkedList* LL = new LinkedList();
                LL->push(node);
                node->count++;
                CLmap[count+1] = LL;
            }
            return node->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (KNmap.count(key) == 1) {
            KNmap[key]->val = value;
            int count = KNmap[key]->count;
            if (count == mincount && CLmap[count]->size == 1) {
                mincount++;
            }
            Node* node = CLmap[count]->pop(KNmap[key]);
            if (CLmap.count(count+1) == 1) {
                CLmap[count+1]->push(node);
                node->count++;
            }
            else {
                LinkedList* LL = new LinkedList();
                LL->push(node);
                node->count++;
                CLmap[count+1] = LL;
            }
        }
        else {
            Node* node = (Node*)malloc(sizeof(Node));
            node->val = value;
            node->key = key;
            node->count = 1;
            KNmap[key] = node;
            if (size < cap) {
                if (CLmap.count(1) == 1){
                    CLmap[1]->push(node);
                }
                else {
                    LinkedList* LL = new LinkedList();
                    LL->push(node);
                    CLmap[1] = LL;
                }
                size++;
            }
            else {
                Node* popnode = CLmap[mincount]->pop(CLmap[mincount]->tail);
                KNmap.erase(popnode->key);
                if (CLmap.count(1) == 1){
                    CLmap[1]->push(node);
                }
                else {
                    LinkedList* LL = new LinkedList();
                    LL->push(node);
                    CLmap[1] = LL;
                }
            }
            mincount = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    int capacity = 2;
    LFUCache* obj = new LFUCache(capacity);
    obj->put(1,1);
    obj->put(2,2);
    int param_1 = obj->get(1);
    cout << param_1 << endl;
    obj->put(3,3);
    int param_2 = obj->get(2);
    cout << param_2 << endl;
    int param_3 = obj->get(3);
    cout << param_3 << endl;
    return 0;
}