//wap to sort words by length 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Comparison function to sort by length
bool compareLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

int main() {
    std::string text = "Write a Cpp program to sort words by length";
    std::vector<std::string> words;
    std::string word;

    // Break the string into individual words
    std::stringstream ss(text);
    while (ss >> word) {
        words.push_back(word);
    }

    // Sort words based on length
    std::stable_sort(words.begin(), words.end(), compareLength);

    // Print the sorted words
    std::cout << "Words sorted by length:\n";
    for (const std::string& w : words) {
        std::cout << w << " ";
    }
    std::cout << "\n";

    return 0;
}
