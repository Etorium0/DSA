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
    int t; // t là chỉ số của phần tử cuối mảng, tức là đỉnh stack
};

void Init(Stack &S)
{
    S.t=-1; //Khi stack chưa có phần tử nào thì top được khởi tạo là -1,
            // nếu khởi tạo t = 0 là SAI vì khi đó sẽ hiểu top tại a[0]
};

void printStack(Stack S)
{
    if (S.t == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = 0; i <= S.t; i++)
    {
        cout << S.arr[i] << " ";
    }
    cout << endl;
}

void Push(Stack &S, int x)
{
    if (S.t >= MAX - 1)
    {
        return;
    }
    S.t++; // tang chi so truoc
    S.arr[S.t] = x; // them phan tu vao stack
}

void Pop(Stack &S)
{
    if (S.t == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    S.t--;
}

int Top(Stack S)
{
    if (S.t == -1)
    {
        return -1;
    }
    return S.arr[S.t];
}

int main()
{
    Stack S;
    Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:" << Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:" << Top(S);
    return 0;
}
