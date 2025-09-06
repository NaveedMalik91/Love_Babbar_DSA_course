#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &arr, int k, int mid)
{
    // can we place cows at,  at-least distance = mid
    int count = 1;
    int pos = arr[0]; // First cow placed at first position
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - pos >= mid)
        {
            count++;
            pos = arr[i]; // one more cow has been placed
        }

        if (count == k)
        {
            return true;
        }
    }
    return false;
}

int solve(int n, int k, vector<int> &arr)
{
    // Write your code here
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = arr[arr.size() - 1] - arr[0];
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ispossible(arr, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> v{1,2,4,8,9};
    int n = 5;
    int k = 3;
    cout<<solve(n,k,v);
    
    return 0;
}
