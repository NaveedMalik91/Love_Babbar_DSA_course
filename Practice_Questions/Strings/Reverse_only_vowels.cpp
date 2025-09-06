#include <bits/stdc++.h>
using namespace std;
bool isvowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); // return 0 or 1
}

string reverseVowels(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        if ((isvowel(s[i])) && (isvowel(s[j])))
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if (isvowel(s[i]) == 0)
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
    string s = "aAbcDeFGhI";
    string str = reverseVowels(s);
    cout<<"Expected String = IebcDAFGha"<<endl;
    cout<<"Actual String = "<<str;
    return 0;
}
