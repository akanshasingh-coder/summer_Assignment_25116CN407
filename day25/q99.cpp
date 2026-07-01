//wap to sort names alphabetically
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::sort

int main() {
    int n;
    std::cout << "Enter the number of names: ";
    std::cin >> n;

    // Clear input buffer to ensure std::getline works correctly next
    std::cin.ignore();

    std::vector<std::string> names;
    std::cout << "Enter " << n << " names:\n";

    for (int i = 0; i < n; ++i) {
        std::string temp_name;
        std::getline(std::cin, temp_name);
        names.push_back(temp_name);
    }

    // Sort names alphabetically using standard library
    std::sort(names.begin(), names.end());

    std::cout << "\nNames in alphabetical order:\n";
    for (const auto& name : names) {
        std::cout << name << "\n";
    }

    return 0;
}
