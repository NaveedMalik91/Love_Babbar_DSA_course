/*
#include<iostream>
using namespace std;
int factorial(int a)
{
    if (a == 0 || a == 1)
    {
        return 1;
        
    }
    return (a * factorial(a-1));
    
    
}
int main(int argc, char const *argv[])
{
    
    int n;
    cout<<"Enter the Number"<<endl;
    cin>>n;
    int result = factorial(n);
    cout<<result;
    
    return 0;
}

//Non recursive solution
#include<iostream>
using namespace std;
void factorial(int n)
{
    if (n == 0 || n == 1)
    {
        cout<<"Factorial of a number 1"<<endl;
        return;
    }
    int fact = 1;
    for (int  i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    cout<<"Factorial of a number is "<<fact<<endl;
    
}
int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    factorial(n);
    return 0;
}*/