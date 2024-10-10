#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        this->left = NULL;
        this->right = NULL;
        this->data = 0;
    }
    Node(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
    friend class Binary;
};

class Binary
{
private:
    Node *root;

public:
    Binary()
    {
        this->root = NULL;
    }

    /*Creation of tree recursive*/
    void insert(int data)
    {
        Node* node = new Node(data);
        if (root == NULL)
        {
            root = node;
            return;
        }
        else{
            queue<Node*> q;
            q.push(root);

            while (!q.empty())
            {
                Node* temp = q.front();
                q.pop();
                if (temp->left == NULL)
                {
                    temp->left = node;
                    return;
                }
                else if (temp->right == NULL)
                {
                    temp->right = node; 
                    return;
                }
                else
                {
                    q.push(temp->left);
                    q.push(temp->right);

                }
                
            }
            
        }
        
    }

    /*Printing the tree*/
    void printTree(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
    Node* getroot()
    {
        return root;
    }
};
int main()
{
    Binary obj;
    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.insert(40);
    obj.insert(50);
    obj.insert(60);
    obj.insert(70);
    obj.insert(80);

    obj.printTree(obj.getroot());
    return 0;
}