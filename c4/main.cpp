#include <iostream>
#include <vector>
using namespace std;

long long swap_count = 0;

// Hàm hoán vị 2 phần tử và tăng số đếm
void swap(int &a, int &b) {
    if (&a != &b) {
        int temp = a;
        a = b;
        b = temp;
        swap_count++;
    }
}

// Hàm partition chọn pivot là phần tử giữa
int partition(vector<int> &arr, int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[high]); // Đưa pivot về cuối
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) { // sắp xếp giảm dần
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa pivot vào đúng vị trí
    return i + 1;
}

// Hàm QuickSort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    quickSort(arr, 0, n - 1);

    for (int x : arr) cout << x << " ";
    cout << "\nSo lan hoan vi: " << swap_count << '\n';

    return 0;
}
