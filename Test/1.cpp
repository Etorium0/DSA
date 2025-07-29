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

void outputGreaterThan(List L, int m)
{
    if (L.head == NULL)
    {
        cout << "List is empty";
        return;
    }
    
    node* p = L.head;
    bool found = false;
    
    while (p != NULL)
    {
        if (p->info > m)
        {
            cout << p->info << " ";
            found = true;
        }
        p = p->next;
    }
    
    if (!found)
    {
        cout << "None";
    }
}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"


    cout<<"\nEnter a number: "; int m; cin>>m;
    cout<<"\nValues greater than "<<m<<": ";
    outputGreaterThan(L,m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}
