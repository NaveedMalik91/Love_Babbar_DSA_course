#include <iostream>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node() {}
    Node(int data)
    {
        this->data = data;
    }

    Node *BST_Inorder(int arr[], int s, int e, int size)
    {
        if (s > e)
        {
            return NULL;
        }
        // 1-case solve krdo
        int mid = s + (e - s) / 2;
        int element = arr[mid];
        Node *root = new Node(element);

        // left recursive call
        root->left = BST_Inorder(arr, s, mid - 1, size);
        // right recursive call
        root->right = BST_Inorder(arr, mid + 1, e, size);

        return root;
    }

    void print(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        print(root->left);
        cout << root->data << " ";
        print(root->right);
    }
};
int main(int argc, char const *argv[])
{
    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int s = 0;
    int e = 7;
    int size = 8;
    Node obj;
    Node *root = obj.BST_Inorder(inorder, s, e, size);

    obj.print(root);
    return 0;
}
