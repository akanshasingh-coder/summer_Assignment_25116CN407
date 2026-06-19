//wap to Print Armstrong numbers in a range
#include<iostream>
using namespace std;
int main(){
    int low, high, num, originalNum, remainder, result;
    cout << "Enter the lower and upper limits: ";
    cin >> low >> high;
    cout << "Armstrong numbers between " << low << " and " << high << " are: ";
    for (num = low; num <= high; num++) {
        originalNum = num;
        result = 0;
        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += remainder * remainder * remainder;
            originalNum /= 10;
        }
        if (result == num)
            cout << num << " ";
    }
    return 0;
}
 