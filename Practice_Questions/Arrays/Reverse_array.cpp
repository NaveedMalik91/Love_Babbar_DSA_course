#include<iostream>
using namespace std;
void reverse_arr(int arr[], int size)
{
    cout<<"Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    int start = 0;
    int end = size-1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
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
