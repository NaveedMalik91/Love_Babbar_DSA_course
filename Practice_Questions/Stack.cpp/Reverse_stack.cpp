#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Optimized helper to insert at bottom
    void insertAtBottom(stack<int> &st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);

        st.push(temp); // Backtrack and push the popped values back
    }

    // Optimized reverse function
    void Reverse(stack<int> &st) {
        if (st.empty()) {
            return;
        }

        int temp = st.top();
        st.pop();
        
        // Recursive call to empty the stack
        Reverse(st);
        
        // Insert elements at the bottom in reverse order
        insertAtBottom(st, temp);
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
    st.push(5);

    // Reverse the stack
    solution.Reverse(st);

    // Display the reversed stack
    cout << "Reversed Stack:" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
