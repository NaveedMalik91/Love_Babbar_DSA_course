#include<bits/stdc++.h>
using namespace std;
void reverse_queue(queue<int> &q)
{
    if (q.size() == 0)
    {
        cout<<"Queue is empty\n";
        return;
    }
    stack<int> st;
    while(!q.empty())
    {
        int val = q.front();
        q.pop();
        st.push(val);
        
    }
    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        q.push(val);
    }

    
    

}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    reverse_queue(q);
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        cout<<val<<" ";

    }
    
    return 0;
}