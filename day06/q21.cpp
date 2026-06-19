//wap to convert decimal to binary
#include<iostream>
using namespace std;
int main()
{
    int num, binaryNum[32], i = 0;
    cout << "Enter a decimal number: ";
    cin >> num;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num /= 2;
        i++;
    }
    cout << "Binary representation: ";
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
    return 0;
}