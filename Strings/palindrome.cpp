#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(const char ch[])
{
    int n = strlen(ch); // Length of the string
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        // Skip non-alphanumeric characters from the start
        while (i <= j && !isalnum(ch[i]))
            i++;
        // Skip non-alphanumeric characters from the end
        while (i <= j && !isalnum(ch[j]))
            j--;

        // Compare characters in a case-insensitive manner
        if (i <= j && tolower(ch[i]) != tolower(ch[j]))
        {
            return false;
        }

        // Move towards the center
        i++;
        j--;
    }

    return true;
}

bool Palindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        while (i <= j && !isalnum(s[i]))
        {
            i++;
            
        }
        while (i <= j && !isalnum(s[j]))
        {
            j--;
          
        }
        if (i <= j && tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }

        i++;
        j--;
    }
    return true;
}

int main()
{
    char ch[100];
    cin.getline(ch, 10);
    bool res1 = ispalindrome(ch);
    if (res1)
    {
        cout << "String is palindrome" << endl;
    }
    else
    {
        cout << "String isn't palindrome" << endl;
    }
    string s;
    getline(cin, s);
    bool res2 = Palindrome(s);
    if (res2)
    {
        cout << "String is palindrome" << endl;
    }
    else
    {
        cout << "String isn't palindrome" << endl;
    }
    return 0;
}
