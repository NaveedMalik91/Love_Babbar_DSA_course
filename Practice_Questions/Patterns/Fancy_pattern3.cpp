#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: "<<endl;
    cin>>n;
    for (int rows = 0; rows < n; rows++)
    {
        for (int space = 0; space < n-rows-1; space++)
        {
            cout<<"-";
        }
        
        int a = rows+1;
        for (int col = 0; col < rows+1; col++)
        {
            cout<<a;
            a++;
        }
        
        int start = 2*rows;
        for (int col = 0; col < rows; col++)
        {
            cout<<start;
            start = start-1;
        }
        
        
        cout<<endl;
        
    }
    
    return 0;
}