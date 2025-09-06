#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    for (int rows = 0; rows < 6; rows++)
    {
        for (int col = 0; col < rows+1; col++ )
        {
            cout<<" * ";
            
        }
        cout<<endl; 
    }
    
    return 0;
}