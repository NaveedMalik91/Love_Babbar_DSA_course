#include<bits/stdc++.h>
using namespace std;
vector<int>NSE(int *arr,int size, vector<int> &ans)
{
    stack<int> st;
    st.push(-1);
    for (int i = size-1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        //smaller element mil gaya
        ans[i] = st.top();
        //curr ele ko stack me daale
        //woh b kisi ele ka smaller ho sakta hai
        st.push(curr);
        
    }
    return ans;
    
}
int main()
{
    int arr[5] = {8,4,6,2,3};
    int size = 5;
    vector<int> ans(size);
    ans = NSE(arr,size,ans);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}