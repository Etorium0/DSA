#include<iostream>
#include<queue>
#include<string>
using namespace std;

//Change infix to postfix

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(string infix) {
    string postfix = "";
    char stack[1000]; // Sử dụng array làm stack
    int top = -1; // Chỉ số đỉnh stack
    
    for (int i = 0; i < infix.length(); i++) 
    {
        char c = infix[i];
        if (isalnum(c)) 
        {
            postfix += c;
        } 
        else if (c == '(') 
        {
            stack[++top] = c;
        } 
        else if (c == ')') 
        {
            while (top >= 0 && stack[top] != '(') 
            {
                postfix += stack[top];
                top--;
            }
            if (top >= 0) top--; // Pop '('
        } 
        else if (isOperator(c)) 
        {
            while (top >= 0 && stack[top] != '(' && getPrecedence(stack[top]) >= getPrecedence(c)) 
            {
                postfix += stack[top];
                top--;
            }
            stack[++top] = c;
        }
    }

    while (top >= 0) {
        postfix += stack[top];
        top--;
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Nhap bieu thuc trung to: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Bieu thuc hau to: " << postfix << endl;

    return 0;
}