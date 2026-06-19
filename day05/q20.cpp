//wap to find largest prime factor
#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
int main(){
    long long num, largestFactor = 0;
    cout << "Enter an integer: ";
    cin >> num;
    while (num % 2 == 0) {
        largestFactor = 2;
        num /= 2;
    }
    for (long long i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            largestFactor = i;
            num /= i;
        }
    }
    if (num > 2)
        largestFactor = num;
    cout << "The largest prime factor is: " << largestFactor;
    return 0;
}