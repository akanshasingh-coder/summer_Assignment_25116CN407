//wap to find product of digits of a number
#include<iostream>
using namespace std;
int main()
{
    int n,i,product=1;
    cout<<"enter the value of n"<<endl;
    cin>>n;
 
    while(n!=0)
    {
        i=n%10;
        product=product*i;
        n=n/10;
    }
    cout<<"the product of digits of the given number is " <<product<<endl;
    return 0;
}