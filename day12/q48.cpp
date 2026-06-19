//wap to write function for perfect number 
#include <iostream>
using namespace std;

bool isPerfect(int num) {
    if (num <= 1) {
        return false;
    }
    int sum = 1; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    if (isPerfect(number)) {
        cout << number << " is a perfect number." << endl;
    } else {
        cout << number << " is not a perfect number." << endl;
    }
    return 0;
}