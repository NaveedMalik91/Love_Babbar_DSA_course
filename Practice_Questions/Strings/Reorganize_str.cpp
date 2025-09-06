#include <bits/stdc++.h>
using namespace std;
string reorganizeString(string s)
{
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++; // will make start = 97;
    }
    char most_freq;
    int freq = INT_MIN;
    // Find most frequent
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > freq)
        {
            freq = hash[i];
            most_freq = i + 'a'; // will return ASCII of 'a'
        }
    }
    // place most frequent
    int index = 0;
    while (freq > 0 && index < s.size())
    {
        s[index] = most_freq;
        freq--;
        index += 2;
    }
    // Any character of most freq char is not placed
    if (freq != 0)
    {
        return "";
    }
    // else make freq of most occur char = 0
    hash[most_freq - 'a'] = 0;

    // place other characters
    // place the pointer to first index i.e 1
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0) // This will ignore i = 0 case as its freq has been set to zero
        {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    return s;
}
int main(int argc, char const *argv[])
{
    string s = "aabbccdef";
    string str = reorganizeString(s);
    cout<<"Reorganized string = "<<str;
    return 0;
}
