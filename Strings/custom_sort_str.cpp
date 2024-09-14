#include<bits/stdc++.h>
using namespace std;

string str;
static bool compare(char ch1, char ch2)
{
    return (str.find(ch1) < str.find(ch2));
}
string customSortString(string order, string s)
{
    str = order;
    sort(s.begin(), s.end(), compare);
    return s;
}
int main(int argc, char const *argv[])
{
    string str = "abcde";
    string order = "cba";
    string s = customSortString(order,str);
    cout<<"Custom sorted string = "<<s;
    return 0;
}
