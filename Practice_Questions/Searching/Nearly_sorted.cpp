#include <iostream>
#include <vector>
using namespace std;
bool Nearly_sorted(vector<int> &arr, int k)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            return true;
        }
        else if (arr[mid - 1] == k)
        {
            return true;
        }
        else if (arr[mid + 1] == k)
        {
            return true;
        }
        else if (k < arr[mid])
        {
            end = mid - 2;
        }
        else if (k > arr[mid])
        {
            start = mid + 2;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    vector<int> v{20, 10, 30, 50, 40, 70, 60};
    int target = 20;
    bool result = Nearly_sorted(v, target);
    if (result == true)
    {
        cout<<"Element found in the array"<<endl;
    }
    else{
        cout<<"Element doesn't found in the array"<<endl;
    }
    
    return 0;
}