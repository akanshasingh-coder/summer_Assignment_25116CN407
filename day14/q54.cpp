// wap to frequency of an element in an array
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
    cout << "Enter the element to find frequency: ";
    cin >> searchElement;
    int frequency = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchElement) {
            frequency++;
        }
    }
    cout << "Frequency of " << searchElement << " is: " << frequency << endl;
    return 0;
}