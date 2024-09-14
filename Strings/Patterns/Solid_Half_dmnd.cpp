#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int rows = 0; rows < n;rows++)
    {
        for (int col = 0; col < rows+1; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    for (int rows = 0; rows < n-1; rows++)
    {
        for (int col = 0; col < n-rows-1; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    
    return 0;
}
