// Take numbers from 1 to N
// MIXTURE OF DUPLICATES AND MISSING
// YOU HAVE TO FIND THAT MISSING NUMBER

#include <iostream>
using namespace std;
void Missing(int arr[], int size)
{
    // Dry run done on rough copy
    int i = 0;
    while (i < size)
    {
        int index = arr[i] - 1; // sort and swap and place values corresponding to indices
        if (arr[i] != arr[index])
        {
            swap(arr[i], arr[index]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1;
        }
    }
 }
int main(int argc, char const *argv[])
{
    int n = 5;
    int arr[n] = {1, 3, 3, 3, 3};
    Missing(arr, n);
    return 0;
}
