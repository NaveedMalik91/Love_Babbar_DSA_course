#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    for (int rows = 0; rows < 10; rows++)
    {
        for (int col = 0; col < 10-rows; col++ )
        {
            cout<<col+1;
            
        }
        cout<<endl;
        
        
    }
    
    return 0;
}