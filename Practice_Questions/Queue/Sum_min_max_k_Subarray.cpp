#include<bits/stdc++.h>
using namespace std;
int min_max_k_size_subarray(vector<int> &nums, int k)
{
    deque<int> dq,dq2;
    int ans = 0;

    // process first window
    for (int i = 0; i < k; i++)
    {
        // first in window
        int element = nums[i];
        // agr queue me curr ele chota hai toh use nikaal do
        while (!dq.empty() && element >= nums[dq.back()])
        {
            dq.pop_back();
        }

        while (!dq2.empty() && element <= nums[dq2.back()])
        {
            dq2.pop_back();
        }
        dq.push_back(i);
        dq2.push_back(i);
    }

    //add min and max of window
    ans+= nums[dq.front()] + nums[dq2.front()];
    for (int i = k; i < nums.size(); i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // removal
        if (!dq2.empty() && i - dq2.front() >= k)
        {
            dq2.pop_front();
        }

        // agr queue me curr ele chota hai toh use nikaal do
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }

        // addition of next element in window
        dq.push_back(i);
        dq2.push_back(i);

        ans+= nums[dq.front()] + nums[dq2.front()];

    }
    return ans;
}

int main()
{
    vector<int> v{2,5,-1,7,-3,-1,-2};
    int k = 4;
    int ans = min_max_k_size_subarray(v,k);
    cout<<ans;
    return 0;
}