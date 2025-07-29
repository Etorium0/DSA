#include <iostream>
using namespace std;

struct Ao
{
    string type;
    int size;
    Ao* next;
};

struct Stack
{
    Ao* top;
};

void Init(Stack &S)
{
    S.top = NULL; // Khởi tạo stack rỗng
}

void Push(Stack &S, string type, int size)
{
    Ao* newNode = new Ao;
    newNode->type = type;
    newNode->size = size;
    newNode->next = S.top;
    S.top = newNode;
}

void Pop(Stack &S)
{
    if (S.top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    Ao* temp = S.top;
    S.top = S.top->next;
    delete temp;
}

string Top(Stack &S, int x)
{
    for (int i = 0; i < x; i++)
    {
        if (S.top != NULL) {
            Pop(S);
        }
    }
    
    if (S.top != NULL) {
        cout << S.top->type << " " << S.top->size;
        return "";
    }
    return "";
}

int main()
{
    Stack S;
    Init(S);
    string type;
    int size;

    while (cin >> type)
    {
        if (type == "-1") break;
        cin >> size;
        Push(S, type, size);
    }
    
    int x;
    cin >> x;
    Top(S, x);
    cout << endl;
}
