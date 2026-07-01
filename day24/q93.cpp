//wap to check string rotation
#include <iostream>
#include <string>

// Function to check if s2 is a rotation of s1
bool isRotation(const std::string& s1, const std::string& s2) {
    // If lengths are different, they cannot be rotations of each other
    if (s1.length() != s2.length()) {
        return false;
    }
    
    // Concatenate s1 with itself
    std::string concatenated = s1 + s1;
    
    // Check if s2 is a substring of the concatenated string
    // std::string::npos is returned if the substring is not found
    if (concatenated.find(s2) != std::string::npos) {
        return true;
    }
    
    return false;
}

int main() {
    std::string s1 = "ABCD";
    std::string s2 = "CDAB";
    
    std::cout << "String 1: " << s1 << "\n";
    std::cout << "String 2: " << s2 << "\n";
    
    if (isRotation(s1, s2)) {
        std::cout << "Result: Yes, they are rotations of each other.\n";
    } else {
        std::cout << "Result: No, they are not rotations of each other.\n";
    }
    
    return 0;
}
