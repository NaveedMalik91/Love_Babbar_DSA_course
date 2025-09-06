#include <bits/stdc++.h>
using namespace std;
class circularQueue
{
private:
    int *arr;
    int front;
    int size;
    int rear;

public:
    circularQueue() {}
    circularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }

    void push(int x)
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

        // maintain circular nature
        else if (rear == size - 1 && front != 0) //first pe position khali hai
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
    void pop()
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

        // maintain circular nature
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

    void print()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size; //updates index as well as moving to first index if needed.
        }
        cout << endl;
    }
};
int main()
{
    circularQueue q(5);

    // Push elements into the queue
    q.push(10);
    cout << "Pushed 10 into the queue.\n";
    q.push(20);
    cout << "Pushed 20 into the queue.\n";
    q.push(30);
    cout << "Pushed 30 into the queue.\n";
    q.push(40);
    cout << "Pushed 40 into the queue.\n";
    q.push(50);
    cout << "Pushed 50 into the queue.\n";

    // Display queue contents
    q.print();

    // Pop one element
    q.pop();
    cout << "Popped one element from the queue.\n";

    // Display queue contents again
    q.print();

    return 0;
}