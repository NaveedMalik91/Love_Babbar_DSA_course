
//Decimal to binary
#include<iostream>
#include<cmath>
using namespace std;
int DectoBin(int n)
{
    int binary = 0;
    int i = 0;
    while (n>0)
    {
        int rem = n&1; //or int rem = n%2;
        binary =(rem * pow(10,i++))+binary;
        n = n>>1; //or n = n/2;

    }
    return binary;
    
}
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int result = DectoBin(n);
    cout<<result;
    return 0;
}




