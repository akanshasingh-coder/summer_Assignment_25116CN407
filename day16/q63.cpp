//wap to find pair with given sum 
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, sum;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> sum;
    cout << "Enter the elements of the array: ";
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> seen;
    bool found = false;

    for (int i = 0; i < n; i++) {
        int complement = sum - arr[i];
        if (seen.find(complement) != seen.end()) {
            cout << "Pair found: " << complement << " and " << arr[i] << endl;
            found = true;
        }
        seen.insert(arr[i]);
    }

    if (!found) {
        cout << "No pair found with the given sum." << endl;
    }

    return 0;
}