#include <iostream>
#include <queue>
using namespace std;
class Node
{
private:
    int val;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    friend class BST;
};

class BST
{
private:
    int val;

public:
    BST() {}
    BST(int val)
    {
        this->val = val;
    }

    Node *BstfromInorder(int inorder[], int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }
        int mid = (s + e) / 2;
        int element = inorder[mid];
        Node *root = new Node(element);

        root->left = BstfromInorder(inorder, s, mid - 1);
        root->right = BstfromInorder(inorder, mid + 1, e);
        return root;
    }

    Node* inorderTraversal(Node* root){
        if(!root){
            return NULL;
        }
        inorderTraversal(root->left);
        cout<<root->val<<" ";
        inorderTraversal(root->right);
    }
};

int main(int argc, char const *argv[])
{
    BST obj;
    int inorder[] = {10, 20, 30, 40, 50, 60};
    int s = 0;
    int size = 6;
    int e = size - 1;
    Node *root = obj.BstfromInorder(inorder, s, e);
    obj.inorderTraversal(root);
    return 0;
}
