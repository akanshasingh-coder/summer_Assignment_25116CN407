//wap to write fucntion to find sum of two numbers
#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

int main() {
    int x = 5, y = 10;
    cout << "Sum of " << x << " and " << y << " is: " << sum(x, y) << endl;
    return 0;
}