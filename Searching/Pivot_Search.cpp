#include <iostream>
#include <vector>
using namespace std;
int Pivot_index(vector<int> &nums)
{
    int start = 0;
    int n = nums.size();
    int end = nums.size()-1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        
        if (start == end)
        {
            return start;
        }
        else if (nums[mid] > nums[mid + 1] && mid+1 < n)
        {
            return mid;
        }
        else if (nums[mid] < nums[mid - 1] && mid-1 >= 0) // add condn so that array doesn't go out of bound
        {
            return mid - 1;
        }
        else if (nums[start] > nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        int mid = start + (end - start) / 2;
    }
    return -1;

}
int Binary_Search(vector<int> &arr,int s,int e,int k)
{
    int n = arr.size();
    //int s = 0; //Redeclation will not give answer as i have to implement binary search on specific portin whosw start and end passed in func
    //int e = n-1;
    int mid = s+(e-s)/2;
    while (s<=e)
    {
        if (k == arr[mid])
        {
            return mid;
        }
        else if(k < arr[mid])
        {
            e = mid-1;
        }
        else if(k > arr[mid])
        {
            s = mid+1;
        }
        mid = s+(e-s)/2;
        
        
    }
    return -1;
}
int search(vector<int> &arr,int target)
{
   int pivot = Pivot_index(arr);
    int ans = -1;
    int n = arr.size();
    //Search in A
    if(target >= arr[0] && target <= arr[pivot])
    {
        ans = Binary_Search(arr,0,pivot,target);
    }
    //Search in B
    else{
        ans = Binary_Search(arr,pivot+1,n-1,target);
    }
    return ans;
}   

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    // v.push_back(6);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    int t = 2;
    int result =search(v,t);
    cout<<result;
    return 0;
}
