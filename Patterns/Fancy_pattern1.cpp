#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: "<<endl;
    cin>>n;
    for (int rows = 0; rows < n; rows++)
    {
        for (int col = 0; col < rows+1; col++)
        {
           cout<<rows+1;
           if (col != rows)
           {
                cout<<"*";
           }
           
        }
        cout<<endl;
    }
    for (int rows = 0; rows < n; rows++)
    {
        for (int col = 0; col < n-rows; col++)
        {
            cout<<n-rows;
            if (col != n-rows-1)
            {
                cout<<"*";
            }
            
        }
        cout<<endl;
    }
    
    return 0;
}