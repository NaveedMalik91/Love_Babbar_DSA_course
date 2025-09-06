#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
    Node *next;
    int data;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    friend class Singly_LL;
};
class Singly_LL
{
private:
    Node *head;

public:
    Singly_LL()
    {
        this->head = NULL;
    }
    Singly_LL(Node *head) //actualy there is no need is we are writing the insert functions
    {
        this->head = head;
    }

    /* Creation of linked list*/
    Node *createNode(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next!= nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return head;
    }

    /*Displayng the Linked list created*/
    void display_LL()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    /*Getting length of linked list*/
    int getLength()
    {
        int count = 0;
        Node* temp = head;
        while (temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
        

    }

    // Insertion at Begining
    void insertHead(int data)
    {
        Node* newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        newNode->next = head;
        head = newNode;

    }

    //Insertion at end
    void insertEnd(int data)
    {
        Node* newnode = new Node(data);
        Node* temp = head;
        if (head == NULL)
        {
            newnode = head;
        }
        
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        
    }
    //Insertion in Between
    void insert_at_pos(int pos,int data)
    {
        int length = getLength();
        if (pos<=1)
        {
            insertHead(data);
        }
        
        else if(pos > length)
        {
            insertEnd(data);
        }
        else{
            Node* newNode = new Node(data);
            Node* temp = head;
            Node* prev = NULL;
            Node* curr = head;
            while (pos !=1) //treated as counter
            {
                prev = curr;
                curr = curr->next;
                pos--;
            }
            prev->next = newNode;
            newNode->next = curr;
        }
        
    }
    //Deletion from a position
    void delete_pos(int pos)
    {
        int length = getLength();
        if(head == NULL)
        {
            cout<<"Linked list is empty"<<endl;
        }
        //first node/head
        else if (pos == 1)
        {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete(temp);
        }
        //last node
        else if(pos == length)
        {
            Node* temp = head;
            Node* prev = NULL;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete(temp);
            
        }
        //in-between node
        else{
            Node* curr = head;
            Node* prev =NULL;
            while (pos!=1)
            {
                prev = curr;
                curr = curr->next;
                pos--;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete(curr);
            

        }
        
    }
    
};

int main()
{
    
    Singly_LL obj;
    obj.createNode(10);
    obj.createNode(20);
    obj.createNode(30);
    obj.createNode(40);
    obj.createNode(50);
    obj.createNode(60);

    obj.insertHead(70);
    obj.insertEnd(80);
    obj.insert_at_pos(3,500);

    obj.delete_pos(7);

    cout<<"Linked list: ";
    obj.display_LL();
    cout<<"The length of linked list = "<<obj.getLength();
    return 0;
}