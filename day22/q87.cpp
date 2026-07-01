//wap to character frequency 
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int freq[256] = {0};  

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    cout << "Character frequencies:" << endl;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << char(i) << ": " << freq[i] << endl;
        }
    }

    return 0;
}