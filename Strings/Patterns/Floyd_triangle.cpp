#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    int start = 1;
    for (int rows = 0; rows < n; rows++)
    {
        for (int col = 0; col < rows+1; col++)
        {
            cout<<start<<" ";
            start++;
        }
        cout<<endl;
    }
    return 0;
}
