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

    /*Creation of tree non-recursive*/
    void insert(int data)
    {
        Node *node = new Node(data);
        if (root == NULL)
        {
            root = node;
            return;
        }
        else
        {
            queue<Node *> q;
            q.push(root);

            while (!q.empty())
            {
                Node *temp = q.front();
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
    Node* getroot(){
        return root;
    }

    void level_order(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            cout<<front->data<<" ";
            if (front->left!=NULL)
            {
               q.push(front->left);
            }
            if (front->right !=NULL)
            {
               q.push(front->right);
            }
        }
    }
};
int main()
{
    Binary obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(6);
    obj.insert(7);

    
    obj.level_order(obj.getroot());
    return 0;
}