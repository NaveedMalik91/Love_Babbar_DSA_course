#include<iostream>
using namespace std;
void reverse_arr(int arr[], int size)
{
    int start = 0;
    int end = size-1;
    cout<<"Array = ";
    while (start < end)
    {
        cout<<arr[start]<<" ";
        cout<<arr[end]<<" ";
        start++;
        end--;
    }
    if (start == end)
    {
        cout<<arr[start];
    }
    
}
int main(int argc, char const *argv[])
{
    int n;
    int arr[n];
    cout<<"Enter the number of values: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    reverse_arr(arr,n);
    return 0;
}
