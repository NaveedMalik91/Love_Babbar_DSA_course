#include<iostream>
using namespace std;
int numRolls(int n, int k, int target)
{
    if (target < 0)
    {
        return 0;
    }
    if(n == 0 && target == 0)
    {
       return 1;
    }
    if (n == 0 && target != 0)
    {
        return 0;
    }
    if(n != 0 && target == 0)
    {
       return 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) //loop untill all faces are checked
    {
        ans = ans+numRolls(n-1,k,target-i); //decrease dice by 1 and the target sum by face that occurred
    }
    return ans;
    
    
}
int main(int argc, char const *argv[])
{
    int n = 2;
    int k = 6;
    int target = 7;
    int res = numRolls(2,6,7);
    cout<<"No. of ways = "<<res; 
    return 0;
}
