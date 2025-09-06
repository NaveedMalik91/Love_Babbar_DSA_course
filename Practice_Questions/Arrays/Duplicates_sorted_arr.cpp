//{1,1,2,2,3,3,4,4} -> {1,2,3,4,----}
#include <iostream>
using namespace std;
void Duplicates(int arr[], int n)
{
    int i = 1;
    int j = 0;
    while (i < n)
    {
        if (arr[i] == arr[j])
        {
            i++;
        }
        else
        {
            j++;
            arr[j] = arr[i];
            i++;
        }
    }
    for (int i = 0; i < j+1; i++)
    {
        cout<<arr[i];
    }
    
}
int main(int argc, char const *argv[])
{
    int n = 10;
    int arr[n] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4};
    Duplicates(arr, n);

    return 0;
}
