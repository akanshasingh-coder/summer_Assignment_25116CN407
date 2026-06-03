//wap to check whether a given number is palindrome or not
#include<iostream>
using namespace std;
int main()
{
    int n,i,rev=0,temp;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    temp=n;
    while(n!=0)
    {
        i=n%10;
        rev=rev*10+i;
        n=n/10;
    }
    if(temp==rev)
    {
        cout<<"the given number is palindrome "<<endl;
    }
    else
    {
        cout<<"the given number is not palindrome "<<endl;
    }
    
    return 0;
}