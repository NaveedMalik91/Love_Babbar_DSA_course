#include<iostream>
using namespace std;
void swap(int a,int b)
{
    cout<<"Before swapping: "<<a<<" "<<b<<endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout<<"The value of a and b is: "<<a<<" "<<b;
}

int main(int argc, char const *argv[])
{
    int a,b;
    cout<<"Enter number-1: "<<endl;
    cin>>a; 
    cout<<"Enter the second number: "<<endl;
    cin>>b;
    swap(a,b);
    return 0;
}
