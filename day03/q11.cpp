//wap to find gcd of two numbers
#include<iostream>
using namespace std;
int main()
{
    int n1,n2,gcd=1;
    cout<<"enter the two numbers you want to check"<<endl;
    cin>>n1>>n2;
    for(int i=1;i<=n1 && i<=n2;i++)
    {
        if(n1%i==0 && n2%i==0)
        {
            gcd=i;
        }
    }
    cout<<"the gcd of the given numbers is " <<gcd<<endl;
    return 0;
}