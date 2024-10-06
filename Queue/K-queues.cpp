#include<bits/stdc++.h>
using namespace std;
class K_queues
{
    public:
    int n;
    int k,freespot;
    int *arr,*front,*rear,*next;
    K_queues(int n, int k)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freespot = 0;
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }
        
        for (int i = 0; i < n; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;

    }
    bool push(int x, int qi)
    {
        if(freespot == -1)
        {
            return false;
        }
        //find freespot
        int index = freespot;
        
        // update freespot
        freespot = next[index];

        //check curr qi is empty or not
        if(front[qi] == -1)
        {
            front[qi] = index;
        }
        //link
        else{
            next[rear[qi]] = index;
        }

        //update next and insert
        next[index] = -1;
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    int pop(int qi)
    {
        if(front[qi] == -1)
        {
            return -1;
        }
        // find index to pop
        int index = front[qi];

        //update front after popping
        front[qi] = next[index];

        //update freespots
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
    ~K_queues()
    {
        delete [] arr;
        delete [] next;
        delete [] front;
        delete [] rear;
    }

};
int main()
{
    K_queues obj(8,3);
    obj.push(10,0);
    obj.push(30,1);
    obj.push(50,2);
    obj.push(20,1);
    obj.push(60,3);
    obj.push(50,3);
    obj.push(60,2);
    obj.push(90,2);
    cout<<"All elements have been pushed successfully\n";

    int a = obj.pop(1);
    int b = obj.pop(2);
    cout<<a<<" "<<b;

    return 0;
}