#include<iostream>
#include<vector>
using namespace std;
bool search(vector<vector<int>> &v,int x)
{
    int rows = v.size(); 
    int cols = v[0].size(); 
    int n = rows*cols;

    int s = 0;
    int e = n-1; 
    
    while (s<=e)
    {
        int mid = s+(e-s)/2; 
        int row_index = mid/cols;
        int col_index = mid%cols;
        int curr_ele = v[row_index][col_index];
        if (curr_ele == x)
        {
            return true;
        }
        else if (curr_ele < x)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1; 
        }
        
    }
    return false;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{1,2,3},{3,4,5},{6,7,8}};
    int x = 7;
    bool res = search(v,x); 
    if (res == true)
    {
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Not found";
    }
    
    return 0;
}
