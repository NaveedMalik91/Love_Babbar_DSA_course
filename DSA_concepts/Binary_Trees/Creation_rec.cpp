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
    Node* getroot()
    {
        return root;
    }

    /*Creation of tree recursive*/
    Node *insert()
    {
        int value;
        cout << "Enter data (-1 for no node): ";
        cin >> value;

        if (value == -1)
            return nullptr;

        Node *newNode = new Node(value);
        cout << "Enter left child of " << value << endl;
        newNode->left = insert();

        cout << "Enter right child of " << value << endl;
        newNode->right = insert();

        return newNode;
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

    /*Inorder Traversal*/
    void inorder(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    /*Preorder Traversal*/
    void preorder(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    /*postorder Traversal*/
    void postorder(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    //Level order traversal
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

    //return root of tree
    Node *root = obj.insert();
    cout << "Created tree is: ";

    //Printing
    obj.printTree(root);
    cout << endl;

    //Traversals
    cout << "In-order Traversal is: ";
    obj.inorder(root);
    cout<<endl;
    cout << "Post-order Traversal is: ";
    obj.postorder(root);
    cout<<endl;
    cout << "Preorder Traversal is: ";
    obj.preorder(root);
    cout<<endl;
    cout << "Level Traversal is: ";
    obj.level_order(root);
    return 0;
}