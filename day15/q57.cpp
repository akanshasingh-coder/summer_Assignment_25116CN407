//wap to reverse array
#include <iostream>
using namespace std;

int main() {
    int arr[10], n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Reversed array is: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}