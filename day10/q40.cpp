//wap to print character pyramid
#include <iostream>

int main() {
    int n = 5;

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n - i - 1; j++) {
            std::cout << " ";
        }

        
        for (int j = 0; j <= i; j++) {
            std::cout << (char)('A' + j);
        }

        
        for (int j = i - 1; j >= 0; j--) {
            std::cout << (char)('A' + j);
        }

    
        std::cout << "\n";
    }

    return 0;
}
