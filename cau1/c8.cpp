#include <iostream>
#include <vector>
using namespace std;

vector<int> temp;

void printArray(vector<int>& arr, int left, int right) {
    cout << "[ ";
    for (int i = left; i <= right; i++) {
        cout << arr[i];
        if (i < right) cout << " ";
    }
    cout << " ]";
}

void Merge(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid + 1;
    int k = 0;

    temp.resize(right - left + 1);

    while (i <= mid && j <= right) {
        int nextValue;

        if (arr[i] < arr[j]) nextValue = arr[i++];
        else nextValue = arr[j++];

        temp[k++] = nextValue;
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int i = 0; i < k; i++) arr[left + i] = temp[i];

    for (int i = 0; i < left; i++) {
        cout << arr[i] << " ";
    }
    
    printArray(arr, left, right);
    
    for (int i = right + 1; i < arr.size(); i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

void MergeSort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MergeSort(arr, 0, n - 1);

    return 0;
}
