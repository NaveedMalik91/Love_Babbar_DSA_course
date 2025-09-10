#include <iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    int search(int arr[], int size, int element)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == element)
            {
                return i;
            }
        }
    }
    Node *construct(int In[], int pre[], int &pre_index, int inorder_start, int inorder_end, int size)
    {
        if (pre_index >= size || inorder_start > inorder_end)
        {
            return NULL;
        }

        // 1 case solve krdo
        int element = pre[pre_index];
        pre_index++;
        Node *root = new Node(element);

        // search element in inorder

        int position = search(In, size, element);

        // searched element ke last aur right me  recursion sambhaal lega

        //attach all the elemenets  from inordersrt to Pos-1 to left of root
        root->left = construct(In, pre, pre_index, inorder_start, position-1, size);

        //attach all the elemenets from Pos+1 to inorder_end to left of root
        root->right = construct(In, pre, pre_index, position+1, inorder_end , size);

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
int main(int argc, char const *argv[])
{

    int pre[] = {2, 8, 10, 6, 4, 12};
    int In[] = {10, 8, 6, 2, 4, 12};
    Node obj;
    int pre_index = 0;
    int inorder_start = 0;
    int inorder_end = 5;
    int size = 6;
    Node* root = obj.construct(In, pre, pre_index, inorder_start, inorder_end, size);
    obj.level_order(root);

    return 0;
}
