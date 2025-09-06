#include<iostream>
using namespace std;
void print_digits(int num)
{
    while (num>0)
    {
        int rem = num%10;
        cout<<rem<<endl;
        num = num/10;
    }
    
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    print_digits(n);
    return 0;
}
