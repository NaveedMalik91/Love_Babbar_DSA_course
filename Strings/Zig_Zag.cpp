#include <bits/stdc++.h>
using namespace std;
string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    vector<string> zigzag(numRows);
    int i = 0; // used to iterate over original string
    int row = 0;
    bool direction = 1; // 1= T->B and 0->BtoT
    while (true)
    {
        if (direction)
        {
            while (row < numRows && i < s.size())
            {
                zigzag[row++].push_back(s[i++]);
            }
            // Direction changed, B->T
            row = numRows - 2;
        }
        else
        {
            while (row >= 0 && i < s.size())
            {
                zigzag[row--].push_back(s[i++]);
            }
            // Direction changed, T->B
            row = 1;
        }
        if (i >= s.size())
        {
            break;
        }
        direction = !direction;
    }
    string ans = "";
    for (int i = 0; i < zigzag.size(); i++)
    {
        ans += zigzag[i];
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    string s = "ABCDEFG";
    int num = 3;
    string str = convert(s, num);
    cout<<"The Zig-Zag form of string is: "<<str;
    return 0;
}
