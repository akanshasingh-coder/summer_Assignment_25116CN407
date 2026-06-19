//wap to find the factorial of a given number
#include<iostream>
using namespace std;
int main() 
{
    int i,n,fact=1;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    cout<<"the factorial of the number is " <<fact<<endl;
    return 0;
}