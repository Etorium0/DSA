#include <iostream>
#include <vector>
using namespace std;

void findGamerLogin(vector<int> &arr, int gamerLogin) 
{
    // Binary search để tìm kiếm nhanh hơn
    int left = 0, right = arr.size() - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == gamerLogin) 
        {
            cout << mid + 1 << endl;
            return;
        }
        else if (arr[mid] < gamerLogin) 
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    cout << "0" << endl;
}

void addGamerAndSort(vector<int> &arr, int gamerLogin)
{
    // Kiểm tra xem game thủ đã online chưa
    int left = 0, right = arr.size() - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == gamerLogin) 
        {
            // Game thủ đã online, không cần thêm lại
            return;
        }
        else if (arr[mid] < gamerLogin) 
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    
    // Tìm vị trí chèn đúng để duy trì thứ tự tăng dần
    left = 0;
    right = arr.size();
    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < gamerLogin) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid;
        }
    }
    
    // Chèn game thủ vào vị trí đúng
    arr.insert(arr.begin() + left, gamerLogin);
}

int main()
{
    vector<int> arr;
    int a;
    while (cin >> a && a != 0) 
    {
        if (a == 1)
        {
            int b;
            cin >> b;
            addGamerAndSort(arr, b);
        }
        else if (a == 2)
        {
            int b;
            cin >> b;
            findGamerLogin(arr, b);
        }
    }
    return 0;
}