//wap to  multiply matrix
#include <iostream>
using namespace std;

int main() {
    int n, m, p;
    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> n >> m;
    cout << "Enter the number of columns of the second matrix: ";
    cin >> p;

    int arr1[n][m], arr2[m][p], result[n][p];

    cout << "Enter the elements of the first matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter the elements of the second matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> arr2[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout << "The product of the matrices is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}