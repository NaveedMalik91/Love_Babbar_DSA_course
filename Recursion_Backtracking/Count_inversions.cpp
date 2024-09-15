#include <bits/stdc++.h>
using namespace std;
long merge(vector<int> &arr, int start, int mid, int end, vector<int> &temp)
{
    int i = start;
    long c = 0;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            c+=mid-i+1;
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    while (start <= end)
    {
        arr[start] = temp[start];
        start++;
    }
    return c;
    
}
long merge_sort(vector<int> &arr, int start,int end, vector<int> &temp)
{
    if (start >= end)
    {
        return 0;
    }
    long c = 0;
    int mid = start + (end-start) / 2;
    c+=merge_sort(arr, start, mid, temp);
    c+=merge_sort(arr, mid + 1, end, temp);
    c+=merge(arr, start, mid,end, temp);
    return c;
}

long count_inversions(vector<int> &arr)
{
    int start = 0;
    long c = 0;
    int end = arr.size() - 1;
    vector<int> temp(arr.size(), 0);
    c=merge_sort(arr, start, end, temp);
    return c;
    
}
int main(int argc, char const *argv[])
{
    vector<int> arr{8, 4, 2, 1};
    int n = 4;
    int start = 0;
    int end = n - 1;
    cout<<"Total Inversons: "<<count_inversions(arr);
    return 0;
}