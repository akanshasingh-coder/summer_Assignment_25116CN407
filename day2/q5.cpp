//wap to find sum of digits of a number
#include<iostream>
using namespace std;
int main()
{
    int n,i,sum=0;
    cout<<"enter the value of n"<<endl;
    cin>>n;
 
    while(n!=0)
    {
        i=n%10;
        sum=sum+i;
        n=n/10;
    }
    cout<<"the sum of digits of the given number is " <<sum<<endl;
    return 0;
}