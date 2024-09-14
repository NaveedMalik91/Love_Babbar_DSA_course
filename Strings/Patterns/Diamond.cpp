#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: "<<endl;
    cin>>n;
    for (int rows = 1; rows <= n; rows++)
    {
        for (int space = 1; space <= n-rows; space++ )
        {
            cout<<" ";
        }
        for (int cols = 1; cols <= rows ; cols++) // if n rows are there then there will be 2n-1 number of cols
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        
        for (int j =0; j < i ; j++)
        {
            cout<<" ";
        }
        for (int j = 0; j < n-i; j++)
        {
            cout<<"* ";
        }
        cout<<endl; 
    }
    return 0;
}

