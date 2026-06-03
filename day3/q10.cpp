//wap to print prime number in a given range
#include<iostream>
using namespace std;
int main()
{
    int i,n1,n2,flag=0;
    cout<<"enter the range you want to check"<<endl;
    cin>>n1>>n2;
    for(i=n1;i<=n2;i++)
    {
        if(i==1 || i==0)
        {
            continue;
        }
        flag=0;
        for(int j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<i<<" ";
        }
    }
    
    return 0;
}