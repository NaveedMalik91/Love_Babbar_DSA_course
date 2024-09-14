#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 2 pointer approach
int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;
    set<pair<int, int>> st;
    while (j < nums.size())
    {
        int diff = abs(nums[j] - nums[i]);
        if (diff == k)
        {
            st.insert({nums[i], nums[j]});
            i++;
            j++;
        }

        else if (diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }
        if (i == j)
        {
            j++;
        }
    }
    return st.size();
}


//2nd way-using binary search
int binary_search(vector<int> &nums, int start, int x)
{
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == x)
        {
            return mid;
        }
        else if (nums[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int find_Pairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (binary_search(nums, i + 1, nums[i] + k) != -1)
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    return ans.size();
}

int main()
{
    vector<int> v{5, 1, 2, 4, 1, 2, 3, 2};
    int k = 2;
    int res1 = findPairs(v, k);
    cout << res1<<endl;
     int res2 = find_Pairs(v, k);
    cout << res2;
    return 0;
}