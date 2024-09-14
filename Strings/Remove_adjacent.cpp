#include<bits/stdc++.h>
using namespace std;
//It will remove if two adjacent elements are there
string removeDuplicates(string s)
{
    string ans = "";
    int index = 0;
    while (index < s.length())
    {
        if (ans.length() > 0 && s[index] == ans[ans.length() - 1])
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[index]);
        }
        index++;
    }
    return ans;
}

//It will remove adjacent elements = k
//aaabbccc -> k=3 adjacent elements will be removed
string removeDuplicates(string s, int k)
{

    stack<pair<char, int>> stk;

    for (char c : s)
    {
        if (!stk.empty() && stk.top().first == c)
        {
            if (++stk.top().second == k)
            {
                stk.pop();
            }
        }
        else
        {
            stk.push({c, 1});
        }
    }
    string result;
    while (!stk.empty())
    {
        auto [ch, cnt] = stk.top();
        stk.pop();
        result.append(ch, cnt);
    }

    reverse(result.begin(), result.end());
    return result;
}
int main() {
    string s = "deeedbbcccbdaa";
    int k = 3;
    cout << removeDuplicates(s, k) << endl; // Output: "aa"
    cout << removeDuplicates(s) << endl;
    return 0;
}