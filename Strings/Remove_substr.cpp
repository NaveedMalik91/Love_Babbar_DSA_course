//Remove occurences of sub-string
#include<bits/stdc++.h>
using namespace std;
string removeOccurrences(string s, string part)
{

    while (s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main(int argc, char const *argv[])
{
    string str = "abccbaabccba";
    string p = "cba";
    string res = removeOccurrences(str,p);
    cout<<res;
    return 0;
}
