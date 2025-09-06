#include<iostream>
using namespace std;
void Min_max(int arr[], int size)
{
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
        
    }
    cout<<"Maximum value in array is: "<<max_val<<endl;
    cout<<"Minimum value in array is: "<<min_val;
}

int main(int argc, char const *argv[])
{
    int n;
    int arr[n];
    cout<<"Enter the total number of values in array: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Min_max(arr,n);
    return 0;
}