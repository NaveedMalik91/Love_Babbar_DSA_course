#include<bits/stdc++.h>
using namespace std;

class deQueue
{
    private:
    int *arr;
    int front;
    int rear;
    int size;
    public:
    deQueue(){}
    deQueue(int size)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        arr = new int[size];
    }

    void push_back(int x)
    {
        // overflow
        if ((front == 0 && rear == size - 1) || ((rear + 1)%size== front)) //rear , front ke pich hai
        {
            cout << "Queue overflown, can't insert more\n";
            return;
        }

        // underflow
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = x;
        }

        // circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = x;
        }

        // normal case
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    void push_front(int x )
    {
        //overflow
        if ((front == 0 && rear == size - 1) || ((rear + 1)%size== front)) //rear , front ke pich hai
        {
            cout << "Queue overflown, can't insert more\n";
            return;
        }
        //empty queue
        else if(rear == -1 && front == -1)
        {
            front++;
            rear++;
            arr[front] = x;
        }
        //circular nature maintain
        else if(front == 0 && rear!= size-1)
        {
            front = size-1;
            arr[front] = x;
        }
        //not empty
        else{
            front--;
            arr[front] = x;   
        }
    }

    void pop_front()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "Underflow condition\n";
            return;
        }

        // single element
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        // circular nature
        // popped element is last
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }

        // normal case
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void pop_back()
    {
        //empty case
        if(front == -1 && rear == -1)
        {
            cout<<"Queue underflow\n";
            return;
           
        }

        //single element
        else if(front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
           
        }
        //circular nature
        else if(rear == 0)
        {
            arr[rear] = -1;
            rear = size-1;
        }

        //normally
        else{
           arr[rear] = -1;
           rear--;
        }
    }

    bool isEmpty()
    {
        return (front == -1 );
    }

    bool isFull()
    {
        return (rear == size-1);
    }

    int getSize()
    {
        if (isEmpty()) return 0;
        return rear-front+1;
    }

};

int main()
{
    deQueue dq(5);

    // Push elements into the deque
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(5);
    dq.push_front(1);

    // Pop from front and back
    dq.pop_front();
    dq.pop_back();

    

    return 0;
}