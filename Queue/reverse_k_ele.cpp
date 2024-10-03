#include<bits/stdc++.h>
using namespace std;
void reverse_first_k(queue<int> &q,int k)
{
    if (q.size() == 0)
    {
        cout<<"Queue is empty\n";
        return;
    }
    stack<int> st;
    for (int i = 0; i < k; i++)
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

    //pop values which need not to be reversesd and push again into queue
    int n = q.size();
    for (int i = 0; i < n-k; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
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
    int k = 3;
    reverse_first_k(q,k);
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        cout<<val<<" ";

    }
    
    return 0;
}