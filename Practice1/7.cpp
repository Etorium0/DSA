#include <iostream>
#include <vector>
using namespace std;

void nhapMang(vector<int> &a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
}

void even(vector<int> &a)
{
    bool foundEven = false;
    int firstEvenIndex;
    int lastEvenIndex;
    int maxEven;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] % 2 == 0)
        {
            firstEvenIndex = i;
            maxEven = a[i];
            foundEven = true;
            break;
        }
    }

    if (!foundEven)
    {
        cout << "Khong co so chan nao trong mang" << endl;
        return;
    }

    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] % 2 == 0)
        {
            lastEvenIndex = i;
            break;
        }
    }

    for (int i = firstEvenIndex; i <= lastEvenIndex; i++)
    {
        if (a[i] % 2 == 0 && a[i] > maxEven)
        {
            maxEven = a[i];
        }
    }

    cout << a[firstEvenIndex] << " la so chan dau tien, co chi so " << firstEvenIndex << " trong mang" << endl;
    cout << a[lastEvenIndex] << " la so chan cuoi cung, co chi so " << lastEvenIndex << " trong mang" << endl;
    cout << "So chan lon nhat: " << maxEven << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    nhapMang(a, n);
    cout << "Mang vua nhap: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    even(a);

    return 0;

}
