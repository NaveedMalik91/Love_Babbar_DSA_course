#include<bits/stdc++.h>
using namespace std;

class Queue
{
    private:
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Queue(){}
    Queue(int size)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        arr = new int[size];
    }

    void push(int x)
    {
        //empty case
        if(front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = x;
        }
        //full queue
        else if(rear == size-1)
        {
            cout << "Queue is full\n";
            return;
        }
        //not empty
        else{
            rear++;
            arr[rear] = x;   
        }
    }

    int pop()
    {
        //empty case
        if(front == -1 && rear == -1)
        {
            cout<<"Queue is empty\n";
            return -1;
        }

        //single element
        else if(front == rear)
        {
            int temp = arr[front];
            arr[rear] = -1;
            front = -1;
            rear = -1;
            return temp;
        }

        //normally
        else{
            int temp = arr[front];
            arr[front] = -1;
            front++;
            return temp;
        }
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
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

    int getFront()
    {
        if(front == -1)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        else{
            return arr[front];
        }
    }

    void print()
    {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for(int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5); // Create a queue of size 5

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Queue after pushes: ";
    q.print();

    cout << "Popped element: " << q.pop() << endl;
    cout << "Queue after pop: ";
    q.print();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.push(60); // This should show "Queue is full" if the queue is full

    return 0;
}
