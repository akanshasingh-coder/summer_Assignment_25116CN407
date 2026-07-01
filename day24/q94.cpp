//wap to compress a string 
#include <iostream>
#include <string>

// Function to compress the input string using Run-Length Encoding
std::string compressString(const std::string& str) {
    if (str.empty()) {
        return "";
    }

    std::string compressed = "";
    int len = str.length();

    for (int i = 0; i < len; i++) {
        // Initialize count for the current consecutive group
        int count = 1;

        // Keep counting as long as the next character matches the current one
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++; // Advance the main loop index
        }

        // Append the character and its frequency to the result string
        compressed += str[i];
        compressed += std::to_string(count);
    }

    // Return compressed string if it's actually smaller, else return original
    return compressed.length() < str.length() ? compressed : str;
}

int main() {
    std::string text = "aaabbccccccd";
    
    std::string compressedText = compressString(text);
    
    std::cout << "Original String: " << text << std::endl;
    std::cout << "Compressed String: " << compressedText << std::endl;
    
    return 0;
}
