//wap to union of array
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter the size of the first array: ";
    cin >> n1;
    cout << "Enter the size of the second array: ";
    cin >> n2;

    int arr1[n1], arr2[n2];
    unordered_set<int> union_elements;

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
        union_elements.insert(arr1[i]);
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
        union_elements.insert(arr2[i]);
    }

    cout << "Union of the arrays: ";
    for (const auto& element : union_elements) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}