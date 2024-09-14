#include <bits/stdc++.h>
using namespace std;
int expand(string s , int i, int j)
{
    int count = 0;

    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}
int countSubstrings(string s)
{
    int totalcount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int oddans = expand(s, i, i);
        int evenans = expand(s, i, i + 1);
        totalcount = totalcount + evenans + oddans;
    }
    return totalcount;
}
int main(int argc, char const *argv[])
{
    string s  = "abaab";
    int res = countSubstrings(s);
    cout<<"Total palindromic substrings in string = "<<res;
    return 0;
}