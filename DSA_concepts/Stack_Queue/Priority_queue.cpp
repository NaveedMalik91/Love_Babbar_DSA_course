#include <bits/stdc++.h>
using namespace std;

// Structure for the elements in the priority queue
class Element
{
public:
    int value;
    int priority;
    Element(){}
    Element(int v, int p) : value(v), priority(p) {} // Constructor
};

// Class for Priority Queue
class PriorityQueue
{
private:
    Element* pr; // Pointer to array of elements
    int size;    // Current size of the queue
    int capacity; // Maximum capacity of the queue

public:
    // Constructor to initialize the priority queue
    PriorityQueue(int cap)
    {
        capacity = cap;
        size = 0;
        pr = new Element[capacity]; // Allocate memory for elements
    }

    // Function to insert a new element into the priority queue
    void enqueue(int value, int priority)
    {
        if (size >= capacity) return; // Prevent overflow

        pr[size] = Element(value, priority); // Add new element
        size++;
    }

    // Function to check the top element
    int peek()
    {
        int highestPriority = INT_MIN;
        int ind = -1;

        // Check for the element with the highest priority
        for (int i = 0; i < size; i++)
        {
            if (highestPriority < pr[i].priority || (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value))
            {
                highestPriority = pr[i].priority;
                ind = i;
            }
        }

        return ind; // Return index of the highest priority element
    }

    // Function to remove the element with the highest priority
    void dequeue()
    {
        int ind = peek(); // Find the position of the highest priority element
        if (ind == -1) return; // Check if the queue is empty

        // Shift elements left to remove the element
        for (int i = ind; i < size - 1; i++)
        {
            pr[i] = pr[i + 1];
        }

        size--; // Decrease the size of the priority queue by one
    }

    // Destructor to free allocated memory
    ~PriorityQueue()
    {
        delete[] pr; // Free allocated memory
    }

    // Function to print the top element
    void printTop()
    {
        int ind = peek();
        if (ind != -1) // Check if index is valid
            cout << pr[ind].value << endl;
        else
            cout << "Queue is empty." << endl;
    }
};

// Driver Code
int main()
{
    // Function Call to insert elements as per priority
    PriorityQueue pq(10); // Specify initial capacity
    pq.enqueue(10, 2);
    pq.enqueue(14, 4);
    pq.enqueue(16, 4);
    pq.enqueue(12, 3);

    // Print the top element
    pq.printTop();

    // Dequeue the top element
    pq.dequeue();
    pq.printTop(); // Print next top element

    // Dequeue the top element
    pq.dequeue();
    pq.printTop(); // Print next top element

    return 0;
}
