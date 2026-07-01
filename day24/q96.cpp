//wap to remove duplicate characters
#include <iostream>
#include <string>
#include <unordered_set>

// Function to remove duplicate characters while preserving order
std::string removeDuplicates(const std::string& str) {
    std::unordered_set<char> seen;
    std::string result = "";

    for (char ch : str) {
        // If the character has not been seen before, add it to the result
        if (seen.find(ch) == seen.end()) {
            result.push_back(ch);
            seen.insert(ch); // Mark the character as seen
        }
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string uniqueStr = removeDuplicates(input);

    std::cout << "String after removing duplicates: " << uniqueStr << std::endl;

    return 0;
}
