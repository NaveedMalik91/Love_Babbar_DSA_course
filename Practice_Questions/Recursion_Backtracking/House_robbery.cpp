#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int size, int index)
{
    int n = nums.size();
    if (index >= n)
    {
        return 0;
    }
    // robb at ith index
    int option1 = nums[index] + solve(nums, n, index + 2);
    // don't robb at ith index
    int option2 = 0 + solve(nums, n, index + 1);
    int finalans = max(option1, option2);
    return finalans;
}
int rob(vector<int> &nums)
{
    int size = nums.size();
    int index = 0;
    int ans = solve(nums, size, index);
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {2,7,9,3,1};
    int res = rob(nums);
    cout<<"Maximum robbed money = "<<res;
    return 0;
}
