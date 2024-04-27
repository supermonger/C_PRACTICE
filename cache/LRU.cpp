#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct Node {
    int val;
    int key;
    Node* next;
    Node* prev;
}Node;

typedef class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size=0;
        LinkedList() {
            size=0;
            head = nullptr;
            tail = nullptr;
        }
        void pushtail(Node* node) {
            if (size==0) {
                head=node;
                tail=node;
            }
            else {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            size++;
        }
        void pushhead(Node* node) {
            if (size==0) {
                head=node;
                tail=node;
            }
            else {
                head->prev = node;
                node->next = head;
                head = node;
            }
            size++;
        }
        Node* pop(Node* node) {
            if (node != head && node != tail) {
                Node* curprev = node->prev;
                Node* curnext = node->next;
                curprev->next = curnext;
                curnext->prev = curprev;
                node->next = nullptr;
                node->prev = nullptr;
            }
            else if (node == head && node != tail) {
                Node* curnext = node->next;
                curnext->prev = nullptr;
                node->next = nullptr;
                head = curnext;
            }
            else if (node != head && node == tail) {
                Node* curprev = node->prev;
                curprev->next = nullptr;
                node->prev = nullptr;
                tail = curprev;
            }
            else {
                head = nullptr;
                tail = nullptr;
            }
            size--;
            return node;
        }

}LinkedList;

class LRUCache {
public:
    int size;
    LinkedList* LL = new LinkedList();
    unordered_map<int, Node*> umap;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        // LL->pushhead(LL->pop(umap[key]));
        if (umap.count(key) == 1) {
            LL->pushhead(LL->pop(umap[key]));
            return LL->head->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // Node* node = (Node*)malloc(sizeof(Node));
        // node->val = value;
        // node->key = key;
        // umap[key] = node;
        // if (LL->size < size) {
        //     cout << "key " << key << "\nval " << value << endl; 
        //     LL->pushhead(node);
        // }
        // else {
        //     int tailkey = LL->tail->key;
        //     umap.erase(tailkey);
        //     LL->pop(LL->tail);
        //     LL->pushhead(node);
        // }
        if (umap.count(key) == 1) {
            umap[key]->val = value;
            LL->pop(umap[key]);
            LL->pushhead(umap[key]);
        }
        else {
            Node* node = (Node*)malloc(sizeof(Node));
            node->val = value;
            node->key = key;
            umap[key] = node;
            if (LL->size < size) {
                LL->pushhead(node);
            }
            else {
                int tailkey = LL->tail->key;
                umap.erase(tailkey);
                LL->pop(LL->tail);
                LL->pushhead(node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);
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