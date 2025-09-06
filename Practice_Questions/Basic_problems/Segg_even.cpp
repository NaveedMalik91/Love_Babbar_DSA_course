#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
     int n;
    cout<<"Enter the total number of values"<<endl;
    cin>>n;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];   
    }
    cout<<"Even numbers are:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout<<arr[i]<<endl;
        }
    }
        
    return 0;
}