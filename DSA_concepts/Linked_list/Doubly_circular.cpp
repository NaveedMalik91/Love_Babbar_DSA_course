#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at end
    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = head->prev = head; // circular link
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    // Insert at start
    void insertStart(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    // Insert at position (1-based index)
    void insertAtPos(int pos, int data) {
        if (head == nullptr || pos <= 1) {
            insertStart(data);
            return;
        }

        Node* temp = head;
        int i = 1;

        while (i < pos - 1 && temp != tail) {
            temp = temp->next;
            i++;
        }

        if (temp == tail) {
            // insert at end
            insertEnd(data);
        } else {
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }


    // Delete node by value
    void deleteNode(int data) {

        //Head is null
        if (head == nullptr) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        // Single node case
        if (head == tail && head->data == data) {
            delete head;
            head = tail = nullptr;
            return;
        }

        // Deleting head
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
            return;
        }

        
        //Any middle or tail to delete
        //Traverse to find the element
        Node* curr = head->next;
        while (curr != head) {
            if (curr->data == data) {

                //Handle the any middle element found
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                //handle the tail case
                if (curr == tail) {
                    tail = curr->prev;
                }

                //delete the tail or middle
                delete curr;
                return;
            }
            curr = curr->next;
        }

        cout << "Node with value " << data << " not found." << endl;
    }

    // Search node by value
    bool search(int data) {
        if (head == nullptr) return false;

        Node* temp = head;
        do {
            if (temp->data == data) return true;
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Display list forward
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)" << endl;
    }
};

int main() {
    DoublyCircularLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "List: ";
    list.display();

    list.insertStart(5);
    cout << "After inserting 5 at start: ";
    list.display();

    list.insertAtPos(3, 25);
    cout << "After inserting 25 at position 3: ";
    list.display();

    if (list.search(20))
        cout << "Node 20 found." << endl;
    else
        cout << "Node 20 not found." << endl;

    list.deleteNode(10);
    cout << "After deleting 10: ";
    list.display();

    list.deleteNode(40);
    cout << "After deleting 40: ";
    list.display();

    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    return 0;
}
