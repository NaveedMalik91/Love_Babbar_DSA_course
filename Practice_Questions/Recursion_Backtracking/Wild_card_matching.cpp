#include<iostream>
using namespace std;
bool ismatched(string& s,string& p,int si,int pi)
{
    if (si == s.size() && pi == p.size())
    {
        return true;
    }
    if (si == s.size() && pi < p.size()) //p ahs some characters
    {
        while(pi < p.size())
        {
            if (p[pi] != '*') // any other char other than *
            {
                return false;
            }
        }
        return true;
    }
    
    //Single character matching
    if (s[si] == p[pi] || p[pi] == '?')
    {
        return ismatched(s,p,si+1,pi+1);
    }


    if (p[pi] == '*')
    {
        //Treat * as null string
        bool caseA = ismatched(s,p,si,pi+1);
        // Allow * to consume any one character
        bool caseB = ismatched(s,p,si+1,pi);

        return caseA || caseB;
    }
    //char doesn't match
    return false;

}
bool is_match(string &s, string p)
{
    int si = 0; // pointers to string  S and P
    int pi = 0;
    return ismatched(s,p,si,pi);
}
int main(int argc, char const *argv[])
{
    string s = "abcdefg";
    string p = "ab*fg";
    is_match(s,p);
    return 0;
}
