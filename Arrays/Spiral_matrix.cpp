#include<iostream>
#include<vector>

using namespace std;
void Spiral(vector<vector<int>> &v)
{
    vector<int> st;
    int rows = v.size();
    int cols = v[0].size();
    int total_ele = rows*cols;

    int start_col = 0;
    int start_row = 0;
    int end_col_idx = cols-1;
    int end_row_idx = rows-1;
    int count = 0;

    while (count<total_ele)
    {
        for (int i = start_col; i <= end_col_idx && count<total_ele; i++)
        {
            st.push_back(v[start_row][i]);
            count++;
        }
        start_row++;
        for (int i = start_row; i <= end_row_idx  && count<total_ele; i++)
        {
            st.push_back(v[i][end_col_idx]);
            count++;
        }
        end_col_idx--;
        for (int i = end_col_idx; i >= start_col  && count<total_ele; i--)
        {
            st.push_back(v[end_row_idx][i]);
            count++;
        }
        end_row_idx--;
        for (int i = end_row_idx; i >= start_row  && count<total_ele; i--)
        {
            st.push_back(v[i][start_col]);
            count++;
        }
        start_col++;
        
    }
    for (int i = 0; i < st.size(); i++)
    {
        cout<<st[i];
    }
    
    

    
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    Spiral(v);
    
    return 0;
}