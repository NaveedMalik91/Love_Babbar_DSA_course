#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int s, int e)
{

    if (s > e)
    {
        return 0;
    }

    int option1 = nums[s] + solve(nums, s + 2, e);
    int option2 = 0 + solve(nums, s + 1, e);
    return max(option1, option2);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    int ans1 = solve(nums, 0, n - 2);
    int ans2 = solve(nums, 1, n - 1);
    int ans = max(ans1, ans2);
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 7, 9, 3, 1};
    int res = rob(nums);
    cout << "Maximum robbed money = " << res;
    return 0;
}