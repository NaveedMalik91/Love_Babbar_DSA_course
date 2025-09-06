#include<iostream>
#include<vector>
using namespace std;
int Missing(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    int ans = -1;
    while (start<=end)
    {
        int diff = arr[mid]-mid;
        if (diff == 1)
        {
            start = mid+1;
            
        }
        else{
            ans = mid;
            end = mid-1;
        }
        mid = start+(end-start)/2;
        
        
    }
    if (ans+1 == 0) //no match ans = -1 returned but usin this condition it will be handled
    {
        return n+1;
    }
    
    else{
        return ans+1;
    }
}
int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3, 4,5,6,7};
    int ans = Missing(nums);
    cout<<"Missing: "<<ans;
    return 0;
}
