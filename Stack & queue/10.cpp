/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};
struct List
{
    node *head,*tail;
};
node* getNode(int x)
{
    node *p=new node;
    if (p)
    {
        p->info=x;
        p->next=NULL;
    }
    return p;
}
void Init (List &L)
{
    L.head=L.tail=NULL;
}



void addTail(List &L, int x)
{
    node* p = getNode(x);
    if (L.head==NULL)
        L.head=L.tail=p;
    else
    {
        L.tail->next=p;
        L.tail = p;
    }
}
void inputList(List &L,int n)
{

    int x;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        addTail(L,x); // them phan tu moi vao cuoi danh sach
    }
}

void outputList(List L)
{
    if (L.head==NULL)
    {
        cout<<"List is empty"; return;
    }

    node *p=L.head;
    while (p)
    {
       cout<<p->info<<" ";
        p=p->next;
    }
}

void insertList(List &L, int x)
{
    node *p = getNode(x);
    if (L.head == NULL || L.head->info >= x) // Insert at the beginning
    {
        p->next = L.head;
        L.head = p;
        if (L.tail == NULL) // If the list was empty
            L.tail = p;
    }
    else
    {
        node *current = L.head;
        while (current->next != NULL && current->next->info < x)
        {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
        if (p->next == NULL) // If inserted at the end
            L.tail = p;
    }
}

int main()
{
    List L;
    Init(L);
    int n,x; cin>>n;
    inputList(L,n);
    cout<<"Created List: ";
    outputList(L);
    cout<<"\nEnter a number to add to the list: ";
    cin>>x;
    insertList(L,x);
    cout<<"\nUpdated List: ";
    outputList(L);
    return 0;
}

