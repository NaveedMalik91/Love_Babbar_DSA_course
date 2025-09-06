// INPUT = {1,2,3,4,4}
// SIZE = 5;
//{1,2,3}
// remove duplicates and print  only unique( 1 2 3 4 5 6 6)-> remove 6->{1 2 3 4 5}
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// void printDuplicates(int arr[], int n)
// {
//     unordered_map<int, int> freq;
//     vector<int> duplicates;
//     // Count the frequency of each element
//     for (int i = 0; i < n; i++)
//     {

//         freq[arr[i]]++;
//     }
//     bool flag = false; // added a flag to check if there are no duplicate elements
//     for (int i = 0; i < n; i++)
//     {
//         if (freq[arr[i]] > 1)
//         {
//             flag = true;
//         }
//         else if (freq[i] == 1)
//         {
//             cout << arr[i] << " ";
//         }
//     }

//     if (!flag)
//     {
//         cout << "No duplicate elements";
//     }
// }

// Find duplicates having freq == 2, print single copy and place inside vector
// Refer problem copy
//{1,1,2,2,3}->{1,2,3}
vector<int> findDuplicates(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int n = nums.size();
    vector<int> v;

    // Calculate the frequency of each element
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }

    unordered_map<int, bool> added; // Corrected initialization
    for (int j = 0; j < n; j++)
    {
        // Find elements that appear exactly twice and haven't been added yet
        if (freq[nums[j]] <= 2 && !added[nums[j]])
        {
            v.push_back(nums[j]);
            added[nums[j]] = true; // Mark as added to avoid duplicates in the result
        }
    }

    return v;
}

int main()
{
    vector<int> v{1, 1, 2, 2, 3};
    vector<int> result = findDuplicates(v);

    // Print the result vector containing duplicates
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}