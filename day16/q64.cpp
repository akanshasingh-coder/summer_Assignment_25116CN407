//wap to remove duplicates from array
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> unique_elements;
    int new_size = 0;

    for (int i = 0; i < n; i++) {
        if (unique_elements.find(arr[i]) == unique_elements.end()) {
            unique_elements.insert(arr[i]);
            arr[new_size++] = arr[i];
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < new_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}