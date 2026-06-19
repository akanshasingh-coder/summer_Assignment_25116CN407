//wap to recursive reverse number 
#include<iostream>
using namespace std;

int reverseNumber(int n, int reversed = 0) {
    if (n == 0) {
        return reversed;
    }
    return reverseNumber(n / 10, reversed * 10 + n % 10);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Reverse of " << num << " is " << reverseNumber(num) << endl;
    return 0;
}