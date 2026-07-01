#include <iostream>
#include <string>
#include <unordered_set>


char findFirstRepeating(const std::string& str) {
    std::unordered_set<char> seen_characters;

    
    for (char ch : str) {
        
        if (seen_characters.find(ch) != seen_characters.end()) {
            return ch;
        }
      
        seen_characters.insert(ch);
    }

   
    return '\0'; 
}

int main() {
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    char result = findFirstRepeating(text);

    if (result != '\0') {
        std::cout << "The first repeating character is: '" << result << "'" << std::endl;
    } else {
        std::cout << "No repeating characters found." << std::endl;
    }

    return 0;
}
