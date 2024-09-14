#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int rows = 0; rows < n; rows++)
    {
        //Print spaces
        for (int col = 0; col < n-rows-1; col++)
        {
            cout<<" ";
        }

        //print half numeric pyramid
        for (int  col = 0; col < rows+1; col++)
        {
            cout<<col+1;
        }
        int start = rows+1-1;
        for (int col = 0; col < rows; col++)
        {
            cout<<start;
            start--;

        }
        
        
        cout<<endl;
        
    }
    
    return 0;
}