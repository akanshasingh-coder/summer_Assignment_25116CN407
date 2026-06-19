//wap to convert binary to decimal
#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(long long n) {
    int decimalValue = 0;
    int i = 0;
    int remainder;

    while (n != 0) {
        remainder = n % 10;          
        n /= 10;                     
        decimalValue += remainder * pow(2, i); 
        ++i;                         
    }
    
    return decimalValue;
}

int main() {
    long long binaryNumber;
    
    cout << "Enter a binary number (e.g., 1101): ";
    cin >> binaryNumber;
    
    cout << "Decimal value: " << binaryToDecimal(binaryNumber) << endl;
    
    return 0;
}