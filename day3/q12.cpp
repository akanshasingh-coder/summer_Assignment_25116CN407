//wap to find lcm of two numbers
#include<iostream>
using namespace std;
int main()
{
    int n1,n2,lcm=1;
    cout<<"enter the two numbers you want to check"<<endl;
    cin>>n1>>n2;
    for(int i=1;i<=n1*n2;i++)
    {
        if(i%n1==0 && i%n2==0)
        {
            lcm=i;
            break;
        }
    }
    cout<<"the lcm of the given numbers is " <<lcm<<endl;
    return 0;
}