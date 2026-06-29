//wap to merge arrays
#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter the size of the first array: ";
    cin >> n1;
    cout << "Enter the size of the second array: ";
    cin >> n2;

    int arr1[n1], arr2[n2], merged[n1 + n2];

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    cout << "Merged array: ";
    for (int l = 0; l < n1 + n2; l++) {
        cout << merged[l] << " ";
    }
    cout << endl;

    return 0;
}