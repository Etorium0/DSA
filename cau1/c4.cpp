#include<iostream>
#include<vector>
using namespace std;

int swapcount = 0;

void QuickSort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        int pivot = arr[mid];
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] > pivot) i++;
            while (arr[j] < pivot) j--;

            if (i <= j) {
                swap(arr[i], arr[j]);
                swapcount++;
                i++;
                j--;
            }
        }

        if (left < j)
            QuickSort(arr, left, j);
        if (i < right)
            QuickSort(arr, i, right);
    }
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Number of times to swap 2 numbers: " << swapcount << endl;

    return 0;
}