//wap to find largest and smallest element in an array
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
    int largest = arr[0];
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    cout << "Largest element: " << largest << endl;
    cout << "Smallest element: " << smallest << endl;
    return 0;
}