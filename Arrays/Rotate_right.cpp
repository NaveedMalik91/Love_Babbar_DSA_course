//Rotate array by bits = k = 2 to right
#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int> &arr,int k)
{
    int size = arr.size();
    vector<int> ans(size);
    for (int i = 0; i < size; i++)
    {
        int new_index = (i+k)%size;
        ans[new_index] = arr[i];
    }
    arr = ans;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}
int main(int argc, char const *argv[])
{
    int k;
    cin>>k;
    vector<int> arr = {10,20,30,40,50,60};
    rotate(arr,k);
    
    return 0;
}
