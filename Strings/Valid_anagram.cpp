#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string a, string b)
{
    int freq[256] = {0};
    for (int i = 0; i < a.length(); i++)
    {
        freq[a[i]]++;
    }
    for (int j = 0; j < b.length(); j++)
    {
        freq[b[j]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    string a = "anagram";
    string t = "nagrama";
    bool res = isAnagram(a,t);
    if (res == true)
    {
        cout<<"A valid anagram"<<endl;
    }
    else{
        cout<<"An Invalid anagram"<<endl;
    }
    
    return 0;
}
