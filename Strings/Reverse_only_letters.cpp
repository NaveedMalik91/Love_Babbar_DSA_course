#include <bits/stdc++.h>
using namespace std;
string reverseOnlyLetters(string s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
    {
        if (isalpha(s[i]) && isalpha(s[j]))
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if (!isalpha(s[i]))
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return s;
}
int main(int argc, char const *argv[])
{
    string str = "ab+cde-fg,h";
    string s = reverseOnlyLetters(str);
    cout<<"Reversed string: "<<s;
    return 0;
}
