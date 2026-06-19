// wap to find the sum of first n natural numbers
#include <iostream>
using namespace std;
int main()
{
    int n, i, sum = 0;
    cout << "enter the valu of n" << endl;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    cout << "the sum of first n natural numbers is" << sum << endl;
    return 0;
}