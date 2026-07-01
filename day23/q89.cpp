//wap to find first non-repeating character
#include <iostream>
#include <string>
#include <vector>

char findFirstNonRepeating(const std::string& str) {
    std::vector<int> charCount(256, 0);

   
    for (char ch : str) {
        
        charCount[static_cast<unsigned char>(ch)]++;
    }

    for (char ch : str) {
        if (charCount[static_cast<unsigned char>(ch)] == 1) {
            return ch; 
        }
    }

    
    return '\0'; 
}

int main() {
    std::string input1 = "geeksforgeeks";
    std::string input2 = "aabbcc";

    char result1 = findFirstNonRepeating(input1);
    char result2 = findFirstNonRepeating(input2);

    
    if (result1 != '\0') {
        std::cout << "First non-repeating character in \"" << input1 << "\" is: " << result1 << "\n";
    } else {
        std::cout << "No non-repeating character found in \"" << input1 << "\"\n";
    }

    if (result2 != '\0') {
        std::cout << "First non-repeating character in \"" << input2 << "\" is: " << result2 << "\n";
    } else {
        std::cout << "No non-repeating character found in \"" << input2 << "\"\n";
    }

    return 0;
}
