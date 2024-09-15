#include <bits/stdc++.h>
using namespace std;
void mergeInplace(vector<int> &v,int start, int mid, int end)
{
    int total_len = (end-start)+1;
    int gap = ceil(total_len/2);
    while (gap>0)
    {
        int i = 0;
        int j = gap+i;
        while (j<=end)
        {
            if (v[i] < v[j])
            {
                i++;
                j++;
            }
            else{
                swap(v[i],v[j]);
            }
        }
        if (gap <=1)
        {
            gap = 0;
        }
        else{
            gap = ceil(gap/2);
        }
        
            
        
    }
}
void mergeSort(vector<int> &v, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    // Divide
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    // Conquer or merge sorted arrays
    mergeInplace(v, start, mid, end);
}
vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{22, -5, 3, 2, 6, -70, 100, 5, 30};
    int n = 9;
    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    sortArray(arr);
    cout << endl;
    cout << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}