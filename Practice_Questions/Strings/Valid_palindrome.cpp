//Check palindrome if we remove atmost one character
#include <bits/stdc++.h>
using namespace std;
bool checkpalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }

        else
        {
            bool ans1 = checkpalindrome(s, i + 1, j);
            bool ans2 = checkpalindrome(s, i, j - 1);
            return ans1 | ans2;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    string s = "ABCRRRCA";
    bool res = validPalindrome(s);
    if (res == true)
    {
        cout << " true" << endl;
    }
    else
    {
        cout << "False";
    }

    return 0;
}
