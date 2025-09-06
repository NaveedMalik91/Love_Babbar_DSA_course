#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: "<<endl;
    cin>>n;
    n = n/2;  // e.g. n = 8; if not done then 8 rows above and 8 rows below will be printed. if we nated only 8 in total we need to divide it bt 2
    for (int rows = 1; rows <= n; rows++)
    {
        for (int space = 1; space <= n-rows; space++ )
        {
            cout<<" ";
        }
        for (int cols = 1; cols <= rows ; cols++) 
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

