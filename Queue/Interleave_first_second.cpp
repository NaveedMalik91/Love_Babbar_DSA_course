#include<bits/stdc++.h>
using namespace std;
void interleaving(queue<int> &first,int k)
{
    queue<int> second;
    //divide into two queues
    int n = first.size();
    for(int i = 0;i<n/2;i++)
    {
        int temp = first.front();
        first.pop();
        second.push(temp);
    }
    //merge both
    //rule:- first ele is from first and second from second queue
    for (int i = 0; i < n-k; i++)
    {
        int temp = second.front();
        second.pop();

        first.push(temp);
       
        temp = first.front();
        first.pop();
        first.push(temp);
    }
    


}
int main()
{ 
    return 0;
} 