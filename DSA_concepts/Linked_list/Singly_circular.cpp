#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class SinglyCircularLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    SinglyCircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Insert at end
    void insertEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head; // Circular link
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Circular link
        }
    }

    // Insert at start
    void insertStart(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head; // Circular link
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head; // Update circular link
        }
    }
    void insertAtPos(int pos, int val)
    {
        Node *newNode = new Node(val);

        // head is null
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        // insert at head
        else if (pos <= 1)
        {
            insertStart(val);
            return;
        }
        // Find position
        Node *temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        // agr toh tail hai
        if (temp == tail || temp->next == head)
        {
            temp->next = newNode;
            tail = newNode;
            newNode->next = head;
        }

        // agr toh middle me hai
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteNode(int data)
    {
        if (head == NULL)
        {
            cout << "Cannot delete from empty list." << endl;
            return;
        }

        // Single node
        if (head == tail && head->data == data)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        // Deleting head
        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }

        // Deleting middle or tail
        Node *prev = head;
        Node *curr = head->next;

        while (curr != head)
        {
            if (curr->data == data)
            {
                prev->next = curr->next;

                // Deleting tail
                if (curr == tail)
                {
                    tail = prev;
                    tail->next = head;
                }

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout << "Node with value " << data << " not found." << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "No element" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)" << endl;
    }

    // Searching for a node in the list
    bool search(int data)
    {
        if (head == NULL)
        { // Case: Empty list
            return false;
        }

        Node *temp = head;
        do
        {
            if (temp->data == data)
            {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false; // If node is not found
    }
};
int main(int argc, char const *argv[])
{
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
    list.insertAtPos(2, 25);
    cout << "After inserting 25 at position 2: ";
    list.display();

    // Searching nodes
    int value = 20;
    if (list.search(value))
    {
        cout << "Node " << value << " found in the list." << endl;
    }
    else
    {
        cout << "Node " << value << " not found in the list." << endl;
    }

    // Deleting nodes
    list.deleteNode(10); // Delete head
    cout << "After deleting 10 (head): ";
    list.display();

    list.deleteNode(40); // Delete tail
    cout << "After deleting 40 (tail): ";
    list.display();

    list.deleteNode(20); // Delete middle node
    cout << "After deleting 20 (middle): ";
    list.display();


    list.deleteNode(30);
    list.display();

    return 0;
}
