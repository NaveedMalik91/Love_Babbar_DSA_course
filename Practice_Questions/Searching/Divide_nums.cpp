#include <iostream>
#include <cmath>
using namespace std;
long long int Division(long long int divi, long long int div)
{
    long long int start = 0;
    long long int end = divi;
    long long int mid = start + (end - start) / 2;
    long long int ans = -1;
    while (start <= end)
    {
        if (mid * div == divi)
        {
            return mid;
        }
        else if (mid * div < divi)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (div * mid > divi)
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{

    long long int a = -3648;
    long long  b = -1;
    long long  result = Division(abs(a), abs(b));
    if ((a < 0 && b > 0) || (a > 0 && b < 0))
    {
        result = -result;
    }
    cout << "Quotient = " << result;
    return 0;
}
