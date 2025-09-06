#include <bits/stdc++.h>
using namespace std;
void mapp(string &str)
{
    char start = 'a';
    char mpp[300] = {0};
    for (auto ch : str)
    {
        if (mpp[ch] == 0)
        {
            mpp[ch] = start;
        }
        start++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        str[i] = mpp[ch];
    }
}
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    mapp(pattern);
    vector<string> ans;
    for (string str : words)
    {
        string temp = str;
        mapp(temp);
        if (temp == pattern)
        {
            ans.push_back(str);
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<string> str = {"abc","qee","gff","def"};
    string pattern = "abb";
    vector<string> ans  = findAndReplacePattern(str,pattern);
    cout<<"String wit the same pattern: ";
    for(auto i:ans)
    {
        cout<<i<< " ";
    }
    return 0;
}
