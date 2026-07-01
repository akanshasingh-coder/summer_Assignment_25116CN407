//wap to create menu driven string operation system 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function declarations
void displayMenu();
void findLength();
void concatenateStrings();
void compareStrings();
void reverseString();
void convertToUppercase();

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Clear the input buffer to handle upcoming string inputs correctly
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                findLength();
                break;
            case 2:
                concatenateStrings();
                break;
            case 3:
                compareStrings();
                break;
            case 4:
                reverseString();
                break;
            case 5:
                convertToUppercase();
                break;
            case 6:
                cout << "\nExiting program. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid selection! Please choose a valid menu option." << endl;
        }
        cout << "\n---------------------------------------------\n";
    } while (choice != 6);

    return 0;
}

// Function to print user menu options
void displayMenu() {
    cout << "\n===== STRING OPERATIONS SYSTEM =====" << endl;
    cout << "1. Find Length of a String" << endl;
    cout << "2. Concatenate Two Strings" << endl;
    cout << "3. Compare Two Strings" << endl;
    cout << "4. Reverse a String" << endl;
    cout << "5. Convert String to Uppercase" << endl;
    cout << "6. Exit" << endl;
}

// Option 1: Find length of a string
void findLength() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Length of the string is: " << str.length() << " characters." << endl;
}

// Option 2: Concatenate two strings
void concatenateStrings() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    
    string result = str1 + str2;
    cout << "Concatenated String: " << result << endl;
}

// Option 3: Compare two strings alphabetically
void compareStrings() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    if (str1 == str2) {
        cout << "Both strings are completely equal." << endl;
    } else if (str1 > str2) {
        cout << "\"" << str1 << "\" comes after \"" << str2 << "\" lexicographically." << endl;
    } else {
        cout << "\"" << str1 << "\" comes before \"" << str2 << "\" lexicographically." << endl;
    }
}

// Option 4: Reverse the given string
void reverseString() {
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);
    
    reverse(str.begin(), str.end());
    cout << "Reversed String: " << str << endl;
}

// Option 5: Convert all lower characters to upper
void convertToUppercase() {
    string str;
    cout << "Enter a lowercase/mixed string: ";
    getline(cin, str);
    
    // Transform each character to uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Uppercase String: " << str << endl;
}
