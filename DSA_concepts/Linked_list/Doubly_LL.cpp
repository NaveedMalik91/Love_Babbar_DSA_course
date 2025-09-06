#include<bits/stdc++.h>
using namespace std;
class Node
{
    private:
    int data;
    Node* prev;
    Node* next;
    public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    friend class Doubly_LL;
};
class Doubly_LL
{
    private:
    Node* head;
    Node* tail;
    public:
    Doubly_LL()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    Doubly_LL(Node* head,Node* tail)
    {
        this->head = head;
        this->tail = tail;
    }

    // Creation of D-Linked list
    Node* create_LL(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return head;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = NULL;
        return head;
        
    }

    //Display LL
    void display()
    {
        Node* temp = head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
        
    }

    //Length of LL
    int getLength()
    {
        Node* temp = head;
        int length = 0;
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            while (temp!=NULL)
            {
                length++;
                temp = temp->next;
            }
            
        }
        return length;
    }

    //Insertion at Start
    void insertStart(int data)
    {   
        if (head == NULL)
        {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            Node* newNode = new Node(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
       
    }

    //Insertion at Position
    void insertPos(int data,int pos)
    {
        int length = getLength();
        if (pos == 1)
        {
            insertStart(data);
        }
        else if(pos >= length)
        {
            insertEnd(data);
        }
        
        Node* newNode = new Node(data);
        Node* curr_ptr = head;
        Node* prev_ptr = NULL;
        while (pos!=1)
        {
            prev_ptr = curr_ptr;
            curr_ptr = curr_ptr->next;
            pos--;
        }
        prev_ptr->next = newNode;
        newNode->next = curr_ptr;
        newNode->prev = prev_ptr;
        curr_ptr->prev = newNode;
         
        
    }

    //Insertion at End
    void insertEnd(int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = NULL;

    }


    //Deletion at Position
    void deletePos(int pos)
    {
        int length = getLength();
        if(head == NULL)
        {
            cout<<"Linked list is empty"<<endl;
        }
        //first node
        else if (pos == 1)
        {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            head->prev = NULL;
            delete(temp);
        }
        //Single element case
        else if(head == tail)
        {
            Node* temp = head;
            delete(temp);
            head = NULL;
            tail = NULL;
        }
        //last node
        else if(pos == length)
        {
            Node* prev_ptr = tail->prev;
            prev_ptr->next  = NULL;
            tail->prev = NULL;
            delete(tail);
            tail = prev_ptr;
             
            
        }
        //in-between node
        else{
            Node* ptr1 = NULL;
            Node* ptr2 = head;
            Node* ptr3 = head->next;
            while (pos!=1)
            {
                ptr1 = ptr2;
                ptr2 = ptr2->next;
                ptr3 = ptr3->next;
                pos--;
                
            }
            ptr1->next = ptr2->next;
            ptr2->next = NULL;
            ptr3->prev = ptr2->prev;
            ptr2->prev = NULL;
            delete(ptr2);

            

        }

    }


};
int main()
{
    Doubly_LL obj;
    obj.create_LL(10);
    obj.create_LL(20);
    obj.create_LL(30);
    obj.create_LL(40);
    obj.create_LL(50);
    obj.create_LL(60);
    obj.create_LL(70);
    obj.create_LL(80);

    obj.insertStart(9);
    obj.insertEnd(100);
    obj.insertPos(500,4);

    obj.deletePos(5);


    cout<<"The Linked list is: ";
    obj.display();
    cout<<endl;

    cout<<"The length of LL is: ";
    cout<<obj.getLength();

    
    return 0;
} 