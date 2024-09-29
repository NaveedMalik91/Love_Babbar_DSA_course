#include<bits/stdc++.h>
using namespace std;
vector<int>PSE(int *arr,int size, vector<int> &ans)
{
    stack<int> st;
    st.push(-1);
    //left to right jaa rahe hai hai 
    //aur curr se piche wale ele compare kr rahe hai
    for (int i = 0; i < size; i++)
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
    ans = PSE(arr,size,ans);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}