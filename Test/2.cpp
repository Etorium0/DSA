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

node* findMax(List &L)
{
    if (L.head == NULL) 
    {
        cout << "List is empty";
        return NULL; // List is empty
    }

    node* maxNode = L.head;
    node* p = L.head->next;

    while (p != NULL)
    {
        if (p->info > maxNode->info)
        {
            maxNode = p;
        }
        p = p->next;
    }
    return maxNode;
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


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
