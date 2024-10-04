#include <bits/stdc++.h>
using namespace std;
void printNeg(int *arr, int k, int n)
{
    deque<int> dq;
    // process first k elements
    for (int i = 0; i < k; i++)
    {
        int ele = arr[i];
        if (ele < 0)
        {
            dq.push_back(i);
        }
    }

    // process remaining window
    for (int index = k; index < n; index++)
    {
        if (dq.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << arr[dq.front()] << " ";
        }

        // kth element tk window ki size se agrr zayad hai
        // toh front se remove krdo
        if (index - dq.front() >= k)
        {
            dq.pop_front();
        }

        // curr window ka curr index ka ele agr negative hai
        // toh back me push krdo
        if (arr[index] < 0)
        {
            dq.push_back(index);
        }
    }

    // last window

    if (dq.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << arr[dq.front()] << " ";
    }
}
int main()
{
    int arr[] = {2,-5,4,-1,-2,0,5};
    int n = 7;
    int k = 3;
    printNeg(arr,k,n);
    return 0;
}