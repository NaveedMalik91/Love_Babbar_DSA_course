#include<iostream>
using namespace std;
bool isprime(int a)
{
    
    if (a == 0 || a == 1)
    {
        return false;
    }
    
    for (int i = 2; i < a; i++)
    {
        if (a % i==0)
        {
            return false;
        }    
    }
    return true;
    
}
void print_prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (isprime(i) == true)
        {
            cout<<i<<" ";
        }
        
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number :";
    cin>>n;
    print_prime(n);
    
    return 0;
}
