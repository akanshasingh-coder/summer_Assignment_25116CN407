//wap to find maximum frequency element 
#include <iostream>
#include <unordered_map>
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

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int max_freq = 0;
    int max_element = arr[0];
    for (const auto& pair : freq) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
            max_element = pair.first;
        }
    }

    cout << "The element with maximum frequency is: " << max_element << endl;
    cout << "Its frequency is: " << max_freq << endl;

    return 0;
}