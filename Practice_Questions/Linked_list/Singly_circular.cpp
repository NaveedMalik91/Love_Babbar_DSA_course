#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class SinglyCircularLinkedList {
    private:
    Node* head;
    Node* tail;

    public:
    SinglyCircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at end
    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Circular link
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Circular link
        }
    }

    // Insert at start
    void insertStart(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Circular link
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head; // Update circular link
        }
    }

    // Insert at specific position
    void insertAtPos(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 0) {
            insertStart(data);
            return;
        }

        Node* temp = head;
        int i = 0;
        while (temp != NULL && i < position - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == tail) { // Inserting at the end
            insertEnd(data);
        } else if (temp != NULL) { // Inserting in the middle
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Position out of bounds." << endl;
        }
    }

    // Delete node from the circular linked list
    void deleteNode(int data)
    {   // Case 1: Empty list
        if (head == NULL) { 
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        // Case 2: Single node list
        if (head == tail && head->data == data) {
            delete head;
            head = NULL;
            tail = NULL;
            cout << "Deleted the only node in the list." << endl;
            return;
        }

        // Case 3: Multiple nodes
        Node* temp = head;
        Node* prev = NULL;

        // If the node to delete is the head
        if (head->data == data) {
            tail->next = head->next; // Update tail's next to new head
            head = head->next; // Move head to next node
            delete temp; // Delete old head
            return;
        }

        // Traversing to find the node to delete
        while (true) {
            prev = temp;
            temp = temp->next;

            // Node found in the middle or end
            if (temp->data == data) {
                prev->next = temp->next;

                // If it's the last node, update the tail
                if (temp == tail) {
                    tail = prev;
                }

                delete temp; // Delete the node
                return;
            }

            if (temp == head) break; // Completed the loop
        }

        // Node not found
        cout << "Node with data " << data << " not found." << endl;
    }

    // Display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)" << endl;
    }

    // Get length of circular linked list
    int getLength() {
        if (head == NULL) return 0;

        int length = 0;
        Node* temp = head;
        do {
            length++;
            temp = temp->next;
        } while (temp != head);

        return length;
    }

    // Searching for a node in the list
    bool search(int data) {
        if (head == NULL) { // Case: Empty list
            return false;
        }

        Node* temp = head;
        do {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false; // If node is not found
    }
};

int main() {
    SinglyCircularLinkedList list;

    // Inserting nodes
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Circular Linked List: ";
    list.display();

    // Insert at start
    list.insertStart(5);
    cout << "After inserting 5 at start: ";
    list.display();

    // Insert at specific position
    list.insertAtPos(25, 2);
    cout << "After inserting 25 at position 2: ";
    list.display();

    // Searching nodes
    int value = 20;
    if (list.search(value)) {
        cout << "Node " << value << " found in the list." << endl;
    } else {
        cout << "Node " << value << " not found in the list." << endl;
    }

    // Deleting nodes
    list.deleteNode(10);  // Delete head
    cout << "After deleting 10 (head): ";
    list.display();

    list.deleteNode(40);  // Delete tail
    cout << "After deleting 40 (tail): ";
    list.display();

    list.deleteNode(20);  // Delete middle node
    cout << "After deleting 20 (middle): ";
    list.display();

    return 0;
}
