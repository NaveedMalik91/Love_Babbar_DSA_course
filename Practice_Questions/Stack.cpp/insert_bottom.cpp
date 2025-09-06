#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    stack<int> helper(stack<int> &st,int x,int curr)
    {
        
        if(st.empty())
        {
            st.push(x);
            //yaha pe hum recurion se bahar aa jayenge
            //aur recursive call k baad jo calls hogi usko execute karte jayege isloye return call hai
            return st;
        }
        int temp = st.top();
        st.pop();
        helper(st,x,curr+1);
        //backtrack and push vallues that were pooped
        st.push(temp);
        //atlast return the stack
        return st;
        
    }
    stack<int> insertAtBottom(stack<int> st,int x){
        if(st.empty())
        {
            return st;
        }
        int curr = 0;
        stack<int> ans = helper(st,x,curr);
        return ans;
    }
};

int main() {
    Solution solution;
    stack<int> st;
    
    // Push some elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    int x = -1; // Element to be inserted at the bottom

    // Call the function to insert element at the bottom
    stack<int> updatedStack = solution.insertAtBottom(st, x);

    // Display the updated stack
    cout << "Stack after inserting " << x << " at the bottom:" << endl;
    while (!updatedStack.empty()) {
        cout << updatedStack.top() << " ";
        updatedStack.pop();
    }
    cout << endl;

    return 0;
}
