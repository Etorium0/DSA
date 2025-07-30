/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};

void insert_node(SinglyLinkedList* llist, int data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);

    if (!llist->head) {
        llist->head = node;
    } else {
        llist->tail->next = node;
    }

    llist->tail = node;
}

void printLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* current = llist->head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverseLinkedList(SinglyLinkedList* llist) {
    if (llist->head == nullptr || llist->head->next == nullptr) {
        return llist->head;
    }

    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = llist->head;
    SinglyLinkedListNode* next = nullptr;

    llist->tail = llist->head; // Update tail to the current head

    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current; // Move prev to current
        current = next; // Move to the next node
    }

    llist->head = prev; // Update head to the new front of the list
    return llist->head;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
