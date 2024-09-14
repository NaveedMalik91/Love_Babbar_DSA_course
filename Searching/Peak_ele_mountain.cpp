#include<iostream>
#include<vector>
using namespace std;
int Mountain_peak(vector<int> &arr,int x)
{
    int s = 0;
    int e = x-1;
    int mid = s+(e-s)/2;
    while (s<e)
    {
        if (arr[mid] < arr[mid+1])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return arr[mid]; //at last one element will be left so you can use any one, mid/s/e;
    
}

int main(int argc, char const *argv[])
{
    vector<int> v{10,20,30,90,70,60,50,40};
    int n = 8;
   int result =  Mountain_peak(v,n);
   cout<<result;
    return 0;
}

