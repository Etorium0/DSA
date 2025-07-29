#include<iostream>
using namespace std;

void QuickSort(int arr[], int left, int right)
{
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);

        int pi = i + 1;

        QuickSort(arr, left, pi - 1);
        QuickSort(arr, pi + 1, right);
    }
}

void sortEvenOdd(int arr[], int n)
{
    int even[n], odd[n];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        } else {
            odd[oddCount++] = arr[i];
        }
    }

    QuickSort(even, 0, evenCount - 1);
    QuickSort(odd, 0, oddCount - 1);

    int index = 0;
    for (int i = 0; i < evenCount; i++) {
        arr[index++] = even[i];
    }
    for (int i = 0; i < oddCount; i++) {
        arr[index++] = odd[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortEvenOdd(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;

    return 0;
}
