#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> nums {1,7,3,4,5,6};
    vector<int> lsum(nums.size(),0);
    vector<int> rsum(nums.size(),0);
    
    for (int i = 1; i < nums.size(); i++)
    {
        lsum[i] = lsum[i-1]+nums[i-1];
       
    }
    for (int i = nums.size()-2; i >= 0; i--)
    {
        rsum[i] = rsum[i+1]+nums[i+1];
        
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (lsum[i]==rsum[i])
        {
            cout<<i;
        }
        
    }
    cout<< -1;
    
    

    return 0;
}
