#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void Wave_mat(vector<vector<int>> &v)
{
    int rows = v.size();
    int cols = v[0].size();
    for (int i = 0; i < cols; i++)
    {
        if ((i & 1) == 0)
        {
            for (int j = 0; j < rows; j++)
            {
                cout<<v[j][i];
            }
            
            
        }
        else{
            for (int k = rows-1; k >= 0; k--)
            {
                cout<<v[k][i];
            }
            
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Wave_mat(v);
    return 0;
}