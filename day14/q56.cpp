//wap to find duplicates in an array
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
    cout << "Duplicate elements are: ";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;
            }
        }
    }
    return 0;
}