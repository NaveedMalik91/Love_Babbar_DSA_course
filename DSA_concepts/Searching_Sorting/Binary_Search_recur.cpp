#include<iostream>
using namespace std;
int Binary_Search(int arr[],int start,int end, int k)
{
    int mid = start+(end-start)/2;
    if (start<=end)
    {
        if (k == arr[mid])
        {
            return mid;
        }
        else if(k < arr[mid])
        {
            return Binary_Search(arr,start,mid-1,k);
        }
        return Binary_Search(arr,mid+1,end,k);
        
        mid = start+(end-start)/2;
        
        
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int arr[n] = {1,2,3,4,5,6,7,8,9,10};
    int start = 0;
    int end = n-1;
    int k;
    cin>>k;
   int ans1 = Binary_Search(arr,start,end,k);
    if (ans1 != -1)
    {
        cout<<"Element found in the array at index = "<<ans1<<endl;
    }
    else{
        cout<<"Element doesn't found in the array!"<<endl;
    }

    return 0;
}
