//wap to write function for armstrong number
#include <iostream>
#include <cmath> // Required for the pow() function

using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num;
    int temp = num;
    int totalDigits = 0;
    int sum = 0;

    // Step 1: Count the total number of digits
    while (temp > 0) {
        temp /= 10;
        totalDigits++;
    }

    temp = num; // Reset temp to the original number

    // Step 2: Calculate the sum of digits raised to the power of totalDigits
    while (temp > 0) {
        int remainder = temp % 10;
        sum += round(pow(remainder, totalDigits)); // round() handles floating-point errors from pow()
        temp /= 10;
    }

    // Step 3: Return true if sum equals the original number, else false
    return (sum == originalNum);
}

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    // Call the function and print the result
    if (isArmstrong(number)) {
        cout << number << " is an Armstrong number.\n";
    } else {
        cout << number << " is not an Armstrong number.\n";
    }

    return 0;
}
