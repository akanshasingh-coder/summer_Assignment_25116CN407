//wap to write funtion to find maximum
#include <iostream>
using namespace std;

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 5, y = 10;
    cout << "Maximum of " << x << " and " << y << " is: " << findMax(x, y) << endl;
    return 0;
}