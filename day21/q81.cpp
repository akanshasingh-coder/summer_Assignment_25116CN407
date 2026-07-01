//wap to find string length without using strlen function
#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }

    cout << "Length of the string: " << length << endl;

    return 0;
}