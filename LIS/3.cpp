#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct List
{
    node *head, *tail;
};

node* getNode(int x)
{
    node *p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void initList(List &L)
{
    L.head = L.tail = NULL;
}

// First : addHead
void addHead(List &L, int x)
{
    node *p = getNode(x);
    if(L.head == NULL)
        L.head = L.tail = p;
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

// Second : addTail
void addTail(List &L, int x)
{    
    node *p = getNode(x);
    if(L.head == NULL)
        L.head = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

// Third : addAfter 
void addAfter(List &L, int a, int b)
{
    node *current = L.head;
    while(current != NULL)
    {
        if(current->data == a)
        {
            node *p = getNode(b);
            p->next = current->next;
            current->next = p;
            if(current == L.tail) 
                L.tail = p;
            return;
        }
        current = current->next;
    }
    addHead(L, b);
}

// Fifth : deleteFirst
void deleteFirst(List &L, int n)
{
    if(L.head == NULL) return;
    
    if(L.head->data == n)
    {
        node *temp = L.head;
        L.head = L.head->next;
        if(L.head == NULL) L.tail = NULL;
        delete temp;
        return;
    }
    
    // Find
    node *current = L.head;
    while(current->next != NULL)
    {
        if(current->next->data == n)
        {
            node *temp = current->next;
            current->next = temp->next;
            if(temp == L.tail) L.tail = current;
            delete temp;
            return;
        }
        current = current->next;
    }
}

//Deletehead
void deleteHead(List &L)
{
    if(L.head == NULL) return;
    node *temp = L.head;
    L.head = L.head->next;
    if(L.head == NULL) L.tail = NULL;
    delete temp;
}

void printList(List L)
{
    node *current = L.head;
    while(current != NULL)
    {
        cout << current->data;
        if(current->next != NULL) cout << " ";
        current = current->next;
    }
    cout << endl;
}

int main() 
{
    List myList;
    initList(myList);
    
    int operation;
    while(cin >> operation && operation != 6)
    {
        if(operation == 0)
        {
            int x;
            cin >> x;
            addHead(myList, x);
        }
        else if(operation == 1)
        {
            int x;
            cin >> x;
            addTail(myList, x);
        }
        else if(operation == 2)
        {
            int a, b;
            cin >> a >> b;
            addAfter(myList, a, b);
        }
        else if(operation == 3)
        {
            int n;
            cin >> n;
            deleteFirst(myList, n);
        }
        else if(operation == 5)
        {
            deleteHead(myList);
        }
    }
    
    printList(myList);
    
    return 0;
}
