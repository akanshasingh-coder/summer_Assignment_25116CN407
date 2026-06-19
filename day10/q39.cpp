//wap to print number pyramid pattern
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        // Print spaces
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
        }
        // Print increasing numbers
        for (int k = 1; k <= i; ++k) {
            cout << k;
        }
        // Print decreasing numbers
        for (int k = i - 1; k >= 1; --k) {
            cout << k;
        }
        cout << endl;
    }

    return 0;
}