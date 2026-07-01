//wap to remove spaces from string
#include <iostream>
#include <string>
#include <algorithm> 

int main() {
    std::string text;

   
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    
    text.erase(std::remove(text.begin(), text.end(), ' '), text.end());

    std::cout << "String without spaces: " << text << std::endl;

    return 0;
}

