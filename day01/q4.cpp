//wap to count digits in a given number 
#include<iostream>
using namespace std;
int main()
{
   int n,count=0;
   cout<<"enter the value of n"<<endl;
   cin>>n;
   while(n!=0)
   {
    n=n/10;
    count++;
   }
   cout<<"the number of digits in the given number is " <<count<<endl;
   return 0;
}