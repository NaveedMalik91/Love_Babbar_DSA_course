#include <iostream>
using namespace std;

class twoStacks {
public:
    int *arr;
    int top1;
    int top2;
    int n;

    // Constructor
    twoStacks(int size) {
        arr = new int[size]; // Allocate an array of given size
        this->n = size;     //storing the size in oanother variable to manipulate if required
        top1 = -1;           // Initialize top1 for stack1
        top2 = size;         // Initialize top2 for stack2 (points to one past the last element)
    }

    // Function to push an integer into stack1.
    void push1(int x) {
        if (top2 - top1 <= 1) { // Check for stack overflow
            return; // Overflow condition
        }
        top1++; // Increment top1
        arr[top1] = x; // Insert element
    }

    // Function to push an integer into stack2.
    void push2(int x) {
        if (top2 - top1 <= 1) { // Check for stack overflow
            return; // Overflow condition
        }
        top2--; // Decrement top2
        arr[top2] = x; // Insert element
    }

    // Function to remove an element from top of stack1.
    int pop1() {
        if (top1 == -1) { // Check for underflow
            return -1; // Indicate underflow
        }
        return arr[top1--]; // Return and decrement top1
    }

    // Function to remove an element from top of stack2.
    int pop2() {
        if (top2 == n) { // Check for underflow
            return -1; // Indicate underflow
        }
        return arr[top2++]; // Return and increment top2
    }

    // Function to print elements of stack1
    void printStack1() {
        cout << "Stack 1: ";
        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to print elements of stack2
    void printStack2() {
        cout << "Stack 2: ";
        for (int i = n - 1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~twoStacks() {
        delete[] arr; // Free allocated memory
    }
};

int main() {
    twoStacks ts(10); // Create a twoStacks object with size 10

    // Push elements into stack1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);
    ts.printStack1(); // Print stack1 after pushes
    ts.printStack2(); // Print stack2

    // Push elements into stack2
    ts.push2(20);
    ts.push2(25);
    ts.printStack1(); // Print stack1
    ts.printStack2(); // Print stack2 after pushes

    // Pop from stack1
    int popped1 = ts.pop1(); // Should return 15
    cout << "Popped from Stack 1: " << popped1 << endl;
    ts.printStack1(); // Print stack1 after pop

    // Pop from stack2
    int popped2 = ts.pop2(); // Should return 25
    cout << "Popped from Stack 2: " << popped2 << endl;
    ts.printStack1(); // Print stack1
    ts.printStack2(); // Print stack2 after pop

    return 0;
}
