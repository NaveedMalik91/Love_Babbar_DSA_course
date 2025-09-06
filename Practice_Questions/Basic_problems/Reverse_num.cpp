#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    bool isneg = false;
    if (n < 0)
    {
        isneg = true;
        n = -n;
    }
    int result = 0;
    while(n>0)
    {
        int rem = n % 10;
        result = result*10+rem;
        n = n/10;
    }
    if (isneg == true)
    {
        cout<<-result;
    }
    else{
        cout<<result;
    }
    
    
    return 0;
}
