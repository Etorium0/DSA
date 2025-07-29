#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x, int &count) {
    int left = 0, right = n - 1;
    count = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        count++; // Đếm mỗi lần so sánh
        
        if (arr[mid] == x) {
            return mid; // Trả về vị trí tìm thấy
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1; // Không tìm thấy
}

int main() {
    int n;
    cin >> n;
    
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int x;
    cin >> x;
    
    int count;
    int position = binarySearch(arr, n, x, count);
    
    if (position != -1) {
        cout << position << endl;
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }
    
    delete[] arr;
    return 0;
}
