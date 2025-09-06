#include<iostream>
using namespace std;
int Binary_Search(int arr[],int n,int k)
{
    int start = 0;
    int end = n-1;
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
//{1,2,3,4,4,4,4,4,5} 
//Target = 4
//index(first_occ)  = 3
int first_occurence(int arr[],int n,int k)
{
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    int ans = -1; //if not found -1 will be returned
    while (start<=end)
    {
        if (k == arr[mid])
        {
            ans = mid;
            end = mid-1;
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
    return ans;
}

//{1,2,3,4,4,4,4,4,5} 
//Target = 4
//index(last_occ)  = 7
int last_occurence(int arr[],int n,int k)
{
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    int ans = -1; //if not found, -1 will be returned
    while (start<=end)
    {
        if (k == arr[mid])
        {
            ans  = mid;
            start = mid+1;
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
    return ans;
}
int main(int argc, char const *argv[])
{
    int n = 12;
    int arr[n] = {1,3,3,3,3,4,5,6,7,8,9,10};
    int k;
    cin>>k;
   int ans1 = Binary_Search(arr,n,k);
    if (ans1 != -1)
    {
        cout<<"Element found in the array at index = "<<ans1<<endl;
    }
    else{
        cout<<"Element doesn't found in the array!"<<endl;
    }

    int ans2 = first_occurence(arr,n,k);
    if (ans2 != -1)
    {
        cout<<"First occ. of element found at index = "<<ans2<<endl;
    }
    else{
        cout<<"Element doesn't found in the array!"<<endl;
    }

    int ans3 = last_occurence(arr,n,k);
    if (ans3 != -1)
    {
        cout<<"Last occ. of element found at index = "<<ans3<<endl;
    }
    else{
        cout<<"Element doesn't found in the array!"<<endl;
    }
    return 0;
}
