#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n; 
    bool is_prime = true;
    if (n == 0 || n == 1)
    {
       is_prime = false;
    }
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0) 
        {
           is_prime = false;
           break;
        }  
        else{
            cout<<"Number is prime"<<endl;
        }
    }
    if (is_prime == true)
    {
        cout<<n<<endl;
    }
    else{
        cout<<"Number is not prime"<<endl;
    }
    
   
    return 0;
}