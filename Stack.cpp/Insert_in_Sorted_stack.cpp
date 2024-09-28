#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &st,int x)
{
    if (x>st.top() || st.empty())
    {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st,x);
    //backtracking
    st.push(temp);

}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    int x = 35;
    insert(st,x);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    

    return 0;
}