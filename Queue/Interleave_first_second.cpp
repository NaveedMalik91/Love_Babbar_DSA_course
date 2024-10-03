#include<bits/stdc++.h>
using namespace std;
void interleaving(queue<int> &first)
{
    queue<int> second;
    //divide into two queues
    int n = first.size();
    for(int i = 0;i<n/2;i++)
    {
        int temp = first.front();
        second.push(temp);
    }
    //merge both
    //rule:- first ele is from first ans second from second queue
    for (int i = 0; i < n/2; i++)
    {
        int temp = second.front();
        second.pop();
        first.push(temp);
        first.pop();
        first.push(temp);
    }
    


}
int main()
{ 
    return 0;
} 