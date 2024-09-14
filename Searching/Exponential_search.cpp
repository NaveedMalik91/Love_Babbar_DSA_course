#include<iostream>
#include<vector>
using namespace std;
int Binary_Search(vector<int> arr,int start,int end,int k)
{
    start = 0;
    int n = arr.size();
    end = n-1;
    int mid = start+(end-start)/2;
    while (start<=end)
    {
        if (k == arr[mid])
        {
            return mid;
        }
        else if(k < arr[mid])
        {
            end = mid-1;
        }
        else if(k > arr[mid])
        {
            start = mid+1;
        }
        mid = start+(end-start)/2;
        
        
    }
    return -1;
}
int Exponential(vector<int> &arr,int n, int k)
{
    if (arr[0] == k)
    {
        return 0; // if element to be searched is at first location then return.
    }
    //otherwise start from next index and find subarray by incresing step bt 2^n/ i*2
    else{
        int i = 1;
        while (i<n && arr[i] <= k)
        {
            i = i*2;
        }
        return Binary_Search(arr,i/2,min(i,n-1),k); //min(i,n-1) -> when we reach at last elements the will get incremented by 2 times and array out of bound so we have to take min value of it which exists in array
    }
    

}
int main(int argc, char const *argv[])
{
    vector<int> v{12,16,22,30,35,39,42,45,48,50,53,55,56};
    int n = v.size();
    int k = 42;
    int res = Exponential(v, n,k);
    cout<<" Element fount at index: "<<res;
    
    return 0;
}
