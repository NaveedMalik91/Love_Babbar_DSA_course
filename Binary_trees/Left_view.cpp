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

    //Left view of tree
    void Print_left_view(Node* root,vector<int> &v, int level)
    {
        int size = v.size();
        if (root == NULL)
        {
            return;
        }

        //if level and size of vector is same so push the root data
        //which will be our left node. in right node case the level become greater than size
        if (level == size)
        {
            v.push_back(root->data);
        }

        //call recursivels on left and right subtree
        Print_left_view(root->left,v,level+1);
        Print_left_view(root->right,v,level+1);

        
        

    }


    void Print_right_view(Node* root,vector<int> &v, int level)
    {
        int size = v.size();
        if (root == NULL)
        {
            return;
        }

        //if level and size of vector is same so push the root data
        //which will be our left node. in right node case the level become greater than size
        if (level == size)
        {
            v.push_back(root->data);
        }

        //call recursivels on left and right subtree
        Print_right_view(root->right,v,level+1);
        Print_right_view(root->left,v,level+1);
    }


    Node* getroot()
    {
        return root;
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

    int level = 0;
    vector<int> v1;
    vector<int> v2;

    obj.Print_left_view(obj.getroot(),v1,level);
    cout<<"Printing left view: ";
    for(auto val:v1)
    {
        cout<<val<<" ";
    }

    cout<<endl;
    cout<<"Printing right view: ";
    obj.Print_right_view(obj.getroot(),v2,level);
    for(auto val:v2)
    {
        cout<<val<<" ";
    }
    return 0;
}