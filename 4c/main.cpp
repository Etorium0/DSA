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
            count++;
        }
    }

    // In count đầu tiên
    cout << count << endl;

    // In các vị trí (index 0-based)
    for (int j = 0; j < n; j++)
    {
        if (x == a[j])
        {
            cout << j << " " << j + 1 << endl;
        }
    }
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
