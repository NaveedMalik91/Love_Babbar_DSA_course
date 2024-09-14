#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
        int sign = 1;
        int i = 0;
        int num = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (i < s.size() && (s[i] == '+') || (s[i] == '-')) {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            if ((num > INT_MAX / 10) || (num == INT_MAX/10 && s[i] > '7')) {
                return sign == -1 ? INT_MIN : INT_MAX;
                
            } else {
                num = num * 10 + (s[i] - '0');
            }
            i++;
        }
        return num * sign;
    }

int main(int argc, char const *argv[])
{
    string s = "    -2232";
    int res = myAtoi(s);
    cout<<"The resultant interger = "<<res;
    return 0;
}
