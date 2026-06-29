//wap to intersection of array
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
    unordered_set<int> intersection_elements;

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Find intersection
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                intersection_elements.insert(arr1[i]);
                break;
            }
        }
    }

    cout << "Intersection of the arrays: ";
    for (const auto& element : intersection_elements) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}