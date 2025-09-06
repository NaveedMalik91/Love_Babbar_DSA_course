#include<iostream>
using namespace std;
void zeroes_ones(int arr[],int size)
{
    int zeroes,ones = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zeroes++;
        }
        if (arr[i] == 1)
        {
            ones++;
        }
        
    }
    cout<<"Number of zeroes in array = "<<zeroes<<endl;
    cout<<"Number of ones in array = "<<ones<<endl;
}

int main(int argc, char const *argv[])
{
    int n;
    int arr[n];
    cout<<"Enter the number of values in array: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    zeroes_ones(arr,n);
    return 0;
}