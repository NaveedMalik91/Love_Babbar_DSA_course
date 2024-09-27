#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr; // Corrected memory deallocation
    }

    void Push(int x) {
        if (top == capacity - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x; // Increment top and then assign value
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty already\n";
            return -1;
        }
        return arr[top--]; // Return value then decrement top
    }

    bool isFull() {
        return top == capacity - 1; // Simplified condition
    }

    bool isempty() {
        return top == -1; // Simplified condition
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isempty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) { // Corrected iteration to display elements
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int ch;
    Stack obj(10);
    while (true) {
        cout << "---------Menu--------\n";
        cout << "1. Push values into stack\n";
        cout << "2. Pop values from stack\n";
        cout << "3. Get top of stack\n";
        cout << "4. Check empty or full stack\n";
        cout << "5. Exit\n"; // Added exit option
        cin >> ch;

        if (ch == 1) {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            obj.Push(value);
            obj.display();
        }
        else if (ch == 2) {
            cout << "Before popping: ";
            obj.display();
            obj.pop();
            cout << "After popping: ";
            obj.display();
        }
        else if (ch == 3) {
            cout << "Top element: " << obj.Top() << endl;
        }
        else if (ch == 4) {
            cout << "Is the stack empty? " << (obj.isempty() ? "Yes" : "No") << endl;
            cout << "Is the stack full? " << (obj.isFull() ? "Yes" : "No") << endl;
        }
        else {
            break; // Exit the loop
        }
    }

    return 0;
}
