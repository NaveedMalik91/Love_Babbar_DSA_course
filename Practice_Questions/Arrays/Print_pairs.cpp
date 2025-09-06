#include <iostream>
using namespace std;
void pairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<arr[i]<<" , "<<arr[j]<<endl;
            
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    int arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pairs(arr, n);
    return 0;
}
//In order to print triplets make two loops as three so that they print three in pairs.
