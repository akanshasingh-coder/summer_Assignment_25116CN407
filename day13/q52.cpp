// wap to count even and odd elements in an array
#include <iostream>
using namespace std;

int main() {
    int arr[10], n;
    int evenCount = 0, oddCount = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    cout << "Even elements: " << evenCount << endl;
    cout << "Odd elements: " << oddCount << endl;
    return 0;
}