#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int sum = 0;
    int rem = 0;
    while(n!=0)
    {
        rem = n % 10;
        sum = sum+rem;
        n = n/10;
    }
    cout<<"The sum of digits of number enterred is: "<<sum;
    int c = 0;
    return 0;
}