#include<iostream>
#include<set>
#include<vector>
using namespace std;
void Common(int arr1[],int arr2[],int arr3[],int n)
{
    int i =0;
    int j = 0;
    int k=0;
    int n1 = 5;
    int n2 = 5;
    int n3 = 5;
    set<int> st; // to remove elements occur multiple times and get common more than once
    while(i<n1 && j<n2 && k<n3)
    {
        if (arr1[i] ==arr2[j] && arr2[j] == arr3[k] )
        {
            st.insert(arr1[i]);
            i++;
            j++;
            k++;
        }
        
        else if (arr1[i]<arr2[j])
        {
            i++;
        }
        else if (arr2[j]<arr3[k])
        {
           j++;
        }
        else
        {
            k++;
        }
        
        
    }
    for(auto i:st)
    {
        cout<<i;
    }
    
}
int main(int argc, char const *argv[])
{
    int n = 5;
    int arr1[5] = {1,2,3,3,5};
    int arr2[5] = {2,3,3,7,8};
    int arr3[5] = {2,3,3,11,66};
    Common(arr1,arr2,arr3,n);
    return 0;
}
