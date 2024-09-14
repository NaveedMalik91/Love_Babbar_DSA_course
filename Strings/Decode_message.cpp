#include<bits/stdc++.h>
using namespace std;
string decodeMessage(string key, string message)
{
    char start = 'a';
    char mapp[300] = {0};
    for (auto ch : key)
    {
        if (ch != ' ' && mapp[ch] == 0)
        {
            mapp[ch] = start;
            start++;
        }
    }
    string ans;
    for (auto ch : message)
    {
        if (ch == ' ')
        {
            ans.push_back(ch);
        }
        else
        {
            char decoded = mapp[ch];
            ans.push_back(decoded);
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    string s= "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    string ans = decodeMessage(s,message);
    cout<<"Decoded message = "<<ans;
    return 0;
}
