#include <bits/stdc++.h>
using namespace std;

void insert_sorted(stack<int> &st, int x) {
    // check karne se pehle yeh dekh lo stack empty toh nahi hai?
    if (st.empty() || x > st.top()) {
        st.push(x);
        return;
    }

    // Store the top element and pop it
    int temp = st.top();
    st.pop();
    insert_sorted(st, x);
    // Backtrack to restore the original stack order
    st.push(temp);
}

void sort_stack(stack<int> &st) {
    // Base case: if the stack is empty, just return
    if (st.empty()) {
        return;
    }

    // Store the top element and pop it
    int temp = st.top();
    st.pop();

    // Sort the remaining stack
    sort_stack(st);

    // Insert the popped element back in sorted order
    insert_sorted(st, temp);
}

int main() {
    stack<int> st;

    // Input: push elements into the stack
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);

    // Sort the stack
    sort_stack(st);

    // Display the sorted stack (largest on top)
    cout << "Sorted Stack (top to bottom):\n";
    while (!st.empty()) {
        cout << st.top() << " "; // Print the top element
        st.pop(); // Pop the element after printing
    }
    cout << endl;

    return 0;
}
