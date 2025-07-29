#include <iostream>
using namespace std;

void inputArray(int* &a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void findElements(int* a, int n, int &m)
{
    int count = 0;

    int x;
    cin >> x;
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
        if (x == a[j])
        {
            cout << j << " ";
            flag = 1;
            count++;
        }
    }
    cout << endl;

    // In các vị trí + 1
    for (int j = 0; j < n; j++)
    {
        if (x == a[j])
        {
            cout << j + 1 << " ";
        }
    }
    cout << endl;
}


int main()
{
    int* a;
    int n, m;

    inputArray(a, n);
    findElements(a, n, m);

    delete[] a;
    return 0;
}
