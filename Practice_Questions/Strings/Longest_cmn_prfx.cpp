#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    int i = 0;
    string ans;
    while (true)
    {
        char ch = 0;
        for (auto str : strs)
        {
            if (i >= str.length())
            {
                ch = 0;
                break;
            }
            if (ch == 0)
            {
                ch = str[i];
            }
            else if (str[i] != ch)
            {
                ch = 0;
                break;
            }
        }
        if (ch == 0)
        {
            break;
        }
        ans.push_back(ch);
        i++;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<string> str{"flower","flow","flowing"};
    string s = longestCommonPrefix(str);
    cout<<"ACTUAL = "<<s<<endl;
    cout<<"ExPECTED = flow"<<endl;
    
    return 0;
}
