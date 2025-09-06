#include <bits/stdc++.h>
// #include<vector>
using namespace std;
int binary_search(vector<int> &nums, int x)
{
    int s = 0;
    int e = nums.size() - 1;
    int ans = e;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] >= x)
        {
            ans = mid;
            e = mid - 1; // Continue to find a smaller index if possible
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

vector<int> printKClosest(vector<int> &nums, int n, int k, int x)
{
    int h = binary_search(nums, x);
    int l = h - 1;
    while (k--)
    {
        if (l < 0)
        {
            h++; // x is first element all closest will lie to right
        }
        else if (h >= nums.size())
        {
            l--; // x is last element all closest will lie to left
        }
        else if (abs(x - nums[l]) > abs(x - nums[h]))
        {
            h++;
        }
        else
        {
            l--;
        }
    }
  
    
    for(int i = l+1;i<=h;i++)
    {
        
        cout<<nums[i]<<" ";
    }
    return vector<int>(nums.begin() + l + 1, nums.begin() + h);;
}
int main(int argc, char const *argv[])
{
    vector<int> v{12,16,22,30,35,39,42,45,48,50,53,55,56};
    int n = v.size();
    int k = 4;
    int x = 35;
    printKClosest(v, n,k,x);
    
    return 0;
}
