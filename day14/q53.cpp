//wap to linear search
#include <iostream>
using namespace std;

int main() {
    int arr[10], n, searchElement;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> searchElement;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchElement) {
            cout << "Element found at index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found" << endl;
    }
    return 0;
}