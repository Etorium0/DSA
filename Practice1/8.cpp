#include<iostream>
#include<vector>
using namespace std;

// input square matrix
void inputSquareMatrix(vector<vector<int>> &matrix, int n) 
{
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    inputSquareMatrix(matrix, n);
    
    
}