//wap to check whether a give number is prime or not
#include<iostream>
using namespace std;
int main()
{
    int i,n,flag=0;
    cout<<"enter the number you want to check"<<endl;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"the given number is prime "<<endl;
    }
    else
    {
        cout<<"the given number is not prime "<<endl;
    }
    return 0;
}