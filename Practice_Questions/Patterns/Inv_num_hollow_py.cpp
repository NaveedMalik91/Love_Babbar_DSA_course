#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int rows = 0; rows<n; rows++)
    {
        for (int col = 0; col < n-rows; col++)
        {
            if (rows == 0)
            {
                cout<<col+1;
            }
            else if(rows == n-1)
            {
                cout<<rows+1;
            }
            else if (col == 0 )
            {
                cout<<rows+1;
            }
            else if(col == n-rows-1)
            {
                cout<<n;
            }
            else
            {
                cout<<" ";
            }
            
            
        }
        cout<<endl;
        
    }
    

    return 0;
}