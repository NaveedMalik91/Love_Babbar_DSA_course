#include<bits/stdc++.h>
using namespace std;
string String_add(string &num1, string &num2, int p1, int p2, int carry)
{
    // base case
    if (p1<0 && p2<0)
    {
        if (carry!=0)
        {
          return string(1,carry+'0');
        }
        return "";
        
    }
    

    // One solution
    int n1 = (p1>=0 ? num1[p1]:'0')-'0'; //If any one string lacks some digits as that of others then add extraa zeroes to it
    int n2 = (p2>=0 ? num2[p2]:'0')-'0';
    int Sum = n1 + n2 + carry;
    int digit = Sum % 10;
    carry = Sum / 10;
    string ans = "";
    ans.push_back(digit + '0');

    // Recursive call
    ans+=String_add(num1, num2, p1 - 1, p2 - 1, carry);
    return ans;
}
int main(int argc, char const *argv[])
{
    string num1 = "123";
    string num2 = "77";
    int p1 = num1.size() - 1;
    int p2 = num2.size() - 1;
    int carry = 0;
    string ans = String_add(num1, num2, p1, p2, carry);
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
