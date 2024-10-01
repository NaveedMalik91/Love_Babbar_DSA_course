#include<bits/stdc++.h>
using namespace std;
class Stack
{
    int *a;
    int *next;
    int *top;
    int n;
    int size;
    int freespot;
    public:
    Stack(int n, int s)
    {
        this->n = n;
        this->size = s;
        this->freespot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i+1;
        }

        next[size-1] = -1;
        
    }


    //push val into mth stack
    bool push(int val, int m)
    {
        //stack overflow
        if(freespot == -1)
        {
            return false;
        }

        //find index
        int index = freespot;

        //update freespot

        freespot = next[index];

        //insert val

        a[index] = val;

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;
        return true;//push successful
    }


    int pop(int m)
    {
        //stack under flow
        if(top[m-1] == -1)
        {
            return -1;
        }

        //find index
        int index = top[m-1];

        top[m-1] = next[index];

        int popped = a[index];
        next[index] = freespot;
        freespot = index;
        return popped;
    }

    ~Stack(){
        delete a;
        delete next;
        delete top; 
    }
};
int main()
{
    Stack obj(3,6);

    obj.push(10,1);
    obj.push(10,1);
    obj.push(10,1);
    obj.push(10,1);
    obj.push(10,1);
    obj.push(10,1);
    cout<<"Six push successful\n";

    cout<<obj.push(10,1)<<endl;
    cout<<"Seventh push unsuccessful";


    return 0;
}