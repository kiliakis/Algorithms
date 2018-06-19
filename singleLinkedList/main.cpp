#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class MyLinkedList {
public:
    int val;
    MyLinkedList *next;
    /** Initialize your data structure here. */

    MyLinkedList() {
        next = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        auto curr = next;
        for (; index > 0; index--) {
            if (curr == NULL) return -1;
            else curr = curr->next;
        }
        if (curr == NULL) return -1;
        else return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList *obj = new MyLinkedList();
        obj->val = val;
        obj->next = next;
        next = obj;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList  *obj = new MyLinkedList();
        obj->val = val;
        obj->next = NULL;
        // if (next == NULL){
        //     next = obj;
        //     return;
        // }
        MyLinkedList  *curr = this;
        while(curr->next != NULL) curr = curr->next;
        curr->next = obj;

    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        MyLinkedList  *obj = new MyLinkedList();
        obj->val = val;
        MyLinkedList  *curr = this;
        
        while(index > 0) {
            if (curr == NULL) return;
            curr = curr->next;
            index--;
        }
        if (curr == NULL) return;
        obj->next = curr->next;
        curr->next = obj;        
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        MyLinkedList  *curr = this;
        
        while(index > 0) {
            if (curr == NULL) return;
            curr = curr->next;
            index--;
        }
        if (curr->next == NULL) return;
        curr->next = curr->next->next;  
    }

        /** Delete the index-th node in the linked list, if the index is valid. */
    void print() {
        MyLinkedList  *curr = next;
        
        while(curr != NULL) {
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */


int main() {
    MyLinkedList *head = new MyLinkedList;
    head->print();
    cout << head->get(0) << "\n";
    head->addAtIndex(1, 2);
    head->print();
    cout << head->get(0) << "\n";
    cout << head->get(1) << "\n";
    head->addAtIndex(0, 1);
    head->print();
    cout << head->get(0) << "\n";
    cout << head->get(1) << "\n";

    // head->addAtHead(1);
    // head->addAtTail(3);
    // head->print();
    // head->print();
    // cout << head->get(1) << "\n";
    // cout << head->get(0) << "\n";
    // cout << head->get(2) << "\n";
    // head->print();
    // head->deleteAtIndex(1);
    // head->print();
    // cout << head->get(1) << "\n";
    return 0;
}

