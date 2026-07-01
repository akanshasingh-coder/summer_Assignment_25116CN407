//wap to find maximum occuring character 
#include <iostream>
#include <string>


char getMaxOccurringChar(const std::string& str) {
    
    int freq[256] = {0};

   
    for (char ch : str) {
        
        freq[static_cast<unsigned char>(ch)]++;
    }

    int maxCount = -1;
    char result = ' ';

    
    for (char ch : str) {
        int currentCharCount = freq[static_cast<unsigned char>(ch)];
        if (currentCharCount > maxCount) {
            maxCount = currentCharCount;
            result = ch;
        }
    }

    return result;
}

int main() {
    std::string inputStr;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputStr);

    if (inputStr.empty()) {
        std::cout << "The string is empty." << std::endl;
        return 0;
    }

    char maxChar = getMaxOccurringChar(inputStr);
    
    std::cout << "The maximum occurring character is: '" << maxChar << "'" << std::endl;

    return 0;
}
