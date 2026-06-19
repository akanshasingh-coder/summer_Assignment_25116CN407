//wap to find x^n without pow()
#include <iostream>
using namespace std;

int main() {
    int x, n, result = 1;
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        result *= x;
    }

    cout << "Result: " << result << endl;
    return 0;
}