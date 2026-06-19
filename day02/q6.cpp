//wap to reverse a number 
#include<iostream>
using namespace std;
int main()
{
    int n,i,rev=0;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    while(n!=0)
    {
        i=n%10;
        rev=rev*10+i;
        n=n/10;
    }
    cout<<"the reverse of the given number is " <<rev<<endl;
    return 0;
}