//RETURN INDEX OF FIRST REPEATING NUMBER
#include <bits/stdc++.h>
using namespace std;

// Function to return the position of the first repeating element.
int firstRepeated(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }
    for (int j = 0; j < n; j++)
    {
        if (freq[nums[j]] > 1)
        {
            return j + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 9, 3, 4, 3, 9, 6};
    int res = firstRepeated(arr);
    cout << res;
    return 0;
}

