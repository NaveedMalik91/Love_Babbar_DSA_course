#include <iostream>
using namespace std;
void Linear_search(int arr[], int n, int k)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            found = true;
            if (found)
            {
                cout << "Element found in the array at index = "<<i << endl;
            }
        }
    }
    if(!found)
    {
        cout << "Element doesn't found in the array" << endl;
    }
}
int main(int argc, char const *argv[])
{
    int n = 15;
    int arr[n] = {0, -1, -3, -5, 10, 4, 77, 32, -54, 100};
    int k;
    cin >> k;
    Linear_search(arr, n, k);

    return 0;
}
