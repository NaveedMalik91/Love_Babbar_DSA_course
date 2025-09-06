#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num)
{
    string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans += sym[i];
            num = num - values[i];
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int num = 1992;
    string res = intToRoman(num);
    cout<<"The result = "<<res;
    return 0;
}
