#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            // Print
            for (int k = 0; k < n; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
            j--;
        }
        arr[j + 1] = key;
        
        // Print
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    InsertionSort(arr);

    return 0;
}
