#include<iostream>
using namespace std;
bool is_even(int n)
{
    if ((n&1) == 0)
    {
        return true;
    }
    else{
        return false;
    }
}
int main(int argc, char const *argv[])
{
    int a;
    cin>>a;
    bool check = is_even(a);
    if (check == true)
    {
        cout<<"Number is Even"<<endl;
    }
    else{
        
        cout<<"Number is Odd"<<endl;
    }
    
    
    return 0;
}
