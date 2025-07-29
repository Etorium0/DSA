/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

void Init(Stack &S)
{
    S.n = 0; // khoi tao stack rong
}

void printStack(Stack S)
{
    if (S.n == 0)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = 0; i < S.n; i++)
    {
        cout << S.arr[i] << " ";
    }
    cout << endl;
}

void Push(Stack &S, int x)
{
    if (S.n >= MAX)
    {
        return;
    }
    S.arr[S.n] = x; // them phan tu vao stack
    S.n++;
}

void Pop(Stack &S)
{
    if (S.n == 0)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    S.n--; // xoa phan tu o dau stack
}

int Top(Stack S)
{
    if (S.n == 0)
    {
        return -1; // tra ve gia tri -1 neu stack rong
    }
        return S.arr[S.n - 1]; // tra ve phan tu o dau stack
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:" << Top(S) << endl;
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:" << Top(S);
    return 0;
}