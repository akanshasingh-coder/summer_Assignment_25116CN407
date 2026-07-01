//wap to find common characters in strings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to find and print common characters
void findCommonCharacters(const std::string& str1, const std::string& str2) {
    // Frequency arrays for all 256 possible ASCII characters
    std::vector<int> freq1(256, 0);
    std::vector<int> freq2(256, 0);

    // Count character frequencies in the first string
    for (char ch : str1) {
        freq1[static_cast<unsigned char>(ch)]++;
    }

    // Count character frequencies in the second string
    for (char ch : str2) {
        freq2[static_cast<unsigned char>(ch)]++;
    }

    std::cout << "Common characters: ";
    bool found = false;

    // Compare frequencies and print the minimum overlap for each character
    for (int i = 0; i < 256; ++i) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            // Find how many times the character is common to both strings
            int commonCount = std::min(freq1[i], freq2[i]);
            for (int j = 0; j < commonCount; ++j) {
                std::cout << static_cast<char>(i) << " ";
            }
            found = true;
        }
    }

    if (!found) {
        std::cout << "None";
    }
    std::cout << std::endl;
}

int main() {
    std::string str1, str2;

    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    findCommonCharacters(str1, str2);

    return 0;
}
