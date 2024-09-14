#include <bits/stdc++.h>
using namespace std;
int countWays(int n, int k)
{
    // code here
    if (n == 1)
    {
        return k;;
    }
    if (n == 2)
    {
        return k+k*(k-1);
    }
    int ans = (k-1)*(countWays(n-1,k)+countWays(n-2,k));
    return ans;
    
    
}
int main()
{
    int n = 3;
    int k = 3;
    int ans = countWays(n,k);
    cout<<"Number of ways = "<<ans;

    return 0;
}