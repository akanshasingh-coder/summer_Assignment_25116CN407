//wap to print factors of a number 
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter an integer: ";
    cin>>num;
    cout<<"Factors of "<<num<<" are: ";
    for(int i=1;i<=num;i++){
        if(num%i==0){
            cout<<i<<" ";
        }
    }
    return 0;
}
