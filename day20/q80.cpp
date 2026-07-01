//wap to find column-wise sum of matrix
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    int arr[n][m];
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Column-wise sum: " << endl;
    for (int j = 0; j < m; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += arr[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }

    return 0;
}