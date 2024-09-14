#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int rows = 0; rows<n; rows++)
    {
        for (int col = 0; col < rows+1; col++)
        {
            if (rows == 0 || rows == n-1)
            {
                cout<<col+1;
            }
            else{
                if (col == 0)
                {
                    cout<<1;
                }
                else if (col == rows+1-1)
                {
                    cout<<rows+1;
                }
                else
                {
                    cout<<" ";
                }
                
                
                
            }
            
            
        }
        cout<<endl;
    }
    
    return 0;
}