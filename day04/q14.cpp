//wap to find nth fibonacci term
#include<iostream>
using namespace std;
int main(){
    int n1=0,n2=1,n3,n;
    cout<<"Enter the term number: ";
    cin>>n;
    if(n==1){
        cout<<"The "<<n<<"th term of Fibonacci series is: "<<n1;
    }
    else if(n==2){
        cout<<"The "<<n<<"th term of Fibonacci series is: "<<n2;
    }
    else{
        for(int i=3;i<=n;i++){
            n3=n1+n2;
            n1=n2;
            n2=n3;
        }
        cout<<"The "<<n<<"th term of Fibonacci series is: "<<n3;
    }
    return 0; 
}