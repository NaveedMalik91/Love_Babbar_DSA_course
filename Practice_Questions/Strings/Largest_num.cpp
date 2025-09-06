#include <bits/stdc++.h>
using namespace std;
static bool mycomp(string a, string b)
{
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2; // return whichever is largest
}
string largestNumber(vector<int> &nums)
{
    vector<string> snums;
    for (auto val : nums)
    {
        snums.push_back(to_string(val));
    }

    sort(snums.begin(), snums.end(), mycomp);

    string ans = "";
    if (snums[0] == "0") // first number is 0 and values sorted in descending order , means after it all will be zeroes
    {
        return "0";
    }
    for (auto str : snums)
    {
        ans += str;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> nums{3,30,34,5,9};
    string res = largestNumber(nums);
    cout<<"Largest number is: "<<res;
    return 0;
}
