#include<bits/stdc++.h>
using namespace std;

bool check_redundant(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int op_cnt = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    op_cnt++;
                }
                st.pop();
            }
            // jab stack empty ho yaa opening bracket mile
            st.pop();
            if (op_cnt == 0)
            {
                return true;
            }
        }
    }
    return false;
}


int main()
{
    string expr1 = "((a+b))"; // Redundant
    string expr2 = "(a+b)";   // Not redundant
    string expr3 = "(a+b)*(c+d)"; // Not redundant
    string expr4 = "(a+b)+(c+d)"; // Not redundant
    string expr5 = "(a+b)*(c+d)+((e*f))"; // Redundant

    cout << "Expression: " << expr1 << " -> " << (check_redundant(expr1) ? "Redundant" : "Not Redundant") << endl;
    cout << "Expression: " << expr2 << " -> " << (check_redundant(expr2) ? "Redundant" : "Not Redundant") << endl;
    cout << "Expression: " << expr3 << " -> " << (check_redundant(expr3) ? "Redundant" : "Not Redundant") << endl;
    cout << "Expression: " << expr4 << " -> " << (check_redundant(expr4) ? "Redundant" : "Not Redundant") << endl;
    cout << "Expression: " << expr5 << " -> " << (check_redundant(expr5) ? "Redundant" : "Not Redundant") << endl;

    return 0;
}