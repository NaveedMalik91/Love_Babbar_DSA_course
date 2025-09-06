#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int rows = 0; rows < n; rows++)
    {
        int col;
        for (col = 0; col < rows+1; col++)
        {
            int ans = col+1;
            char ch = ans + 'A'-1;
            cout<<ch<<" ";
        }
        int a;
        a = col-1; // start from last column
        for (int col = a; col >= 1; col--)//print until reaches 1
        {
            int ans = col;
            char ch = ans + 'A'-1;
            cout<<ch<<" "; 
        }
        
        cout<<endl;
        
    }
    
    return 0;
}