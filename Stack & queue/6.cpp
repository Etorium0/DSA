#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isOpenBracket(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool isCloseBracket(char c)
{
    return (c == ')' || c == '}' || c == ']');
}

bool isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int latexCheck(string s)
{
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        
        if (isOpenBracket(c))
        {
            st.push(c);
        }
        else if (isCloseBracket(c))
        {
            if (st.empty())
            {
                return 0; // Không có dấu mở tương ứng
            }
            
            char topChar = st.top();
            if (!isMatchingPair(topChar, c))
            {
                return 0; 
            }
            st.pop();
        }
    }
    
    if (st.empty())
    {
        return 1; 
    }
    else
    {
        return 0; 
    }
}

int main()
{
    string s;
    getline(cin, s);
    
    cout << latexCheck(s) << endl;
    
    return 0;
}
