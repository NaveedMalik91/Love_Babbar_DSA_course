#include <iostream>
using namespace std;
void Insertion_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
       int key = arr[i];
       int j = i-1;
       while (j>=0 && arr[j] > key)
       {
            arr[j+1] = arr[j];
            j--;
       }
       arr[j+1] = key;
       
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int n = 5;
    int arr[n] = {5, 4, 3, 2, 1};
    Insertion_sort(arr, n);
    return 0;
}
