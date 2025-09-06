#include<iostream>
using namespace std;
void print_subarr(int arr[],int n,int i,int j)
{
    
    if (j==n)
    {
        return;
    }
    if (j<n)
    {
        for (int k = i; k <= j; k++)
        {
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        
    }
    return print_subarr(arr,n,i,j+1);
    
    
}
void print_subarr_next(int arr[],int n)
{
    for (int start = 0; start<=n; start++)
    {
        int j = start;
        print_subarr(arr,n,start,j);
    }
    
}
int main(int argc, char const *argv[])
{   int arr[10] = {1,2,3,4,5};
    int n = 5;
    int i = 0;
    int j = 0;
    print_subarr_next(arr,n);
    return 0;
}
