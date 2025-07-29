#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node
{
    int info;
    node *next;
};


struct List
{
    node *head;
    node *tail;
};

void Init(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

node* getNode(int x)
{
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addTail(List &L, int x)
{
    node* p = getNode(x);
    if (L.head == NULL)
    {
        L.head = L.tail = p;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void inputList(List &L, int n)
{
    if (n <= 0) return; 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addTail(L, x);
    }
}

void outputList(List L)
{
    if (L.head == NULL)
    {
        cout << "List is empty";
        return;
    }
    
    node* p = L.head;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

node* findElement(List &L, int index)
{
    if (L.head == NULL) 
    {
        cout << "List is empty";
        return NULL; // List is empty
    }
    if (index <= 0) 
    {
        cout << "The index is invalid";
        return NULL; // Invalid index (index starts from 1)
    }
    
    node* p = L.head;
    for (int i = 1; i < index && p != NULL; i++)
    {
        p = p->next;
    }
    
    if (p == NULL)
    {
        cout << "The index is invalid";
        return NULL;
    }
    
    return p; // Returns the node if found
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<": ";
    node *p = findElement(L,i);
    if(p) cout<<p->info;

    return 0;
}
