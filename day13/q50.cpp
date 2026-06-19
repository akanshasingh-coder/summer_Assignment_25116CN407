//wap to find sum and average of array elements
#include <iostream>
using namespace std;

int main() {
    int arr[10], n;
    int sum = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    double average = (double)sum / n;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    return 0;
}