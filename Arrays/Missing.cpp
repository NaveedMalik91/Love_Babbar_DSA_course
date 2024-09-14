#include <bits/stdc++.h>
using namespace std;

int missingNumber(int x, vector<int> &nums)
{

    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) //remember the value is one less/ missing so loop will be upto n-1 if i dont get size by using nums.size()
    {
        sum = sum + nums[i];
    }
    int total_sum = (n * (n + 1)) / 2;
    int result = (total_sum)-sum;
    return result;

}

//2nd Way
void XOR(int x, vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans^nums[i];
    }
    for (int i = 0; i <= x-1; i++)
    {
        ans = ans^i;
    }
    cout<< ans;
    

}

  


int main()
{
    int n = 10;
    vector<int> nums{1,2,3,4,6,7,8,9,0};
    int result = missingNumber(n,nums);
    cout<<result;
    XOR(10,nums);
    
    return 0;
}
