//wap to check strong number
#include<iostream>
using namespace std;
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main() {
    int num, originalNum, remainder, result = 0;
    cout << "Enter an integer: ";
    cin >> num;
    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += factorial(remainder);
        originalNum /= 10;
    }
    if (result == num)
        cout << num << " is a Strong number.";
    else
        cout << num << " is not a Strong number.";
    return 0;
}