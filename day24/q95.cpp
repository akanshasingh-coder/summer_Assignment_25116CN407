//wap to find longest word
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence;
    std::string current_word;
    std::string longest_word = "";

    // Prompt the user for input
    std::cout << "Enter a sentence: ";
    
    // Read the complete line including spaces
    std::getline(std::cin, sentence);

    // Use stringstream to break the sentence into individual words
    std::stringstream string_stream(sentence);

    // Extract words one by one
    while (string_stream >> current_word) {
        // Update the longest word if the current one is longer
        if (current_word.length() > longest_word.length()) {
            longest_word = current_word;
        }
    }

    // Output the results
    if (longest_word.empty()) {
        std::cout << "No words found." << std::endl;
    } else {
        std::cout << "The longest word is: " << longest_word << std::endl;
        std::cout << "Its length is: " << longest_word.length() << " characters." << std::endl;
    }

    return 0;
}
