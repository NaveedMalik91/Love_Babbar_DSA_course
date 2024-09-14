#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void odd_occur(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }
    for (int j = 0; j < n; j++)
    {
        if (freq[nums[j]] % 3)
        {
            cout << "Element occuring odd number of time = " << nums[j];
        }
    }
    
}

int main()
{
    vector<int> v{1, 1, 2, 3, 3, 4, 4, 5, 5};
    odd_occur(v);
    return 0;
}