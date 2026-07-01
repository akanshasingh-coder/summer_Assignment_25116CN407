//wap to check anagram strings
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isAnagram(const string& str1, const string& str2) {
    
    if (str1.length() != str2.length()) {
        return false;
    }

   
    vector<int> charCount(256, 0);

    
    for (size_t i = 0; i < str1.length(); ++i) {
        charCount[static_cast<unsigned char>(str1[i])]++;
        charCount[static_cast<unsigned char>(str2[i])]--;
    }

  
    for (int count : charCount) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string string1, string2;

    cout << "Enter the first string: ";
    cin >> string1;

    cout << "Enter the second string: ";
    cin >> string2;

    if (isAnagram(string1, string2)) {
        cout << "\"" << string1 << "\" and \"" << string2 << "\" are anagrams." << endl;
    } else {
        cout << "\"" << string1 << "\" and \"" << string2 << "\" are NOT anagrams." << endl;
    }

    return 0;
}
