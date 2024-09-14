#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int> &v, vector<int> &temp, int start, int mid, int end)
{
    // first array = start -> mid
    // second array = mid+1 -> end
    // merged array = start -> end
    int i = start, j = mid + 1;

    //yeh bahut important point hai, hum temp k andhar
    //waha se insertion peform karenge jaha se humara original array start hoga
    //suppose 2 sorted array hai from index 5-7 and 9-11. in that case hum 5 se start karenge
    int k = start; 


    //Sort wala part
    while (i <= mid && j <= end)
    {
        if (v[i] < v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }

    // Agr arays ka size differ ho
    // toh waaki ke elements ko handle kro
    while (i <= mid)
    {
        temp[k++] = v[i++];
    }
    while (j <= end)
    {
        temp[k++] = v[j++];
    }

    // merged data ko copy karo temp vector se original vector k amdhar
    while (start <= end)
    {
        v[start] = temp[start];
        start++;
    }
}
void mergeSort(vector<int> &v, int start, vector<int> &temp, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    // Divide
    mergeSort(v, start, temp, mid);
    mergeSort(v, mid + 1, temp, end);
    // Conquer or merge sorted arrays
    merge(v, temp, start, mid, end);
}
vector<int> sortArray(vector<int> &nums)
{
    // temp storage to store sorted array
    vector<int> temp(nums.size(), 0);
    mergeSort(nums, 0, temp, nums.size() - 1);
    return nums;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{22, -5, 3, 2, 6, -70, 100, 5, 30};
    int n = 9;
    int start = 0;
    int end = n - 1;
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
