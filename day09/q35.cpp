//wap to print repeated character pattern 
//A
//BB
//CCC
//DDDD
//EEEEE
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<(char)(i+64)<<" ";
        }
        cout<<endl;
    }
    return 0;
}