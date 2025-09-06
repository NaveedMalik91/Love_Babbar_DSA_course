//also known as painter partition problem
#include <bits/stdc++.h>
using namespace std;
bool ispossiblesolution(int arr[], int n, int m, int sol)
{
    int pagesum = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sol)
        {
            return false;
        }
        if (pagesum + arr[i] > sol)
        {
            count++;
            pagesum = arr[i];
            if (count > m)
            {
                return false;
            }
        }
        else
        {
            pagesum += arr[i];
        }
    }
    return true;
}
// Function to find minimum number of pages.
long long findPages(int n, int arr[], int m)
{
    // code here
    if (m > n)
    {
        return -1;
    }
    int start = 0;
    int end = accumulate(arr, arr + n, 0);
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ispossiblesolution(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int arr[5] = {12,34,67,90};
    int n = 5;
    int m = 2;
    int res = findPages(n,arr,m);
    cout<<res;
    return 0;
}
