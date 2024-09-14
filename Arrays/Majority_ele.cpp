#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int n = nums.size();
    int count = 0;
    int majority_ele  = nums[1];
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }
    for (int j = 0; j < n; j++)
    {
        if (freq[nums[j]] > count)
        {
            count = freq[nums[j]];
            majority_ele = nums[j];
        }
    }
    return majority_ele;
}

int main()
{
	vector<int> nums = {3, 3, 3, 3, 6, 7, 8};
	cout << "The majority element is: " << majorityElement(nums) << endl;
	return 0;
}