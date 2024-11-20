#include<iostream>
#include<queue>
using namespace std;
class Node{
    private:
    int val;
    Node* left;
    Node*right;
    public:
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    friend class BST;
};
class BST{
    private:
    int val;
    public:
    BST(){}
    BST(int val){
        this->val = val;
    }
    Node* createBST(Node* root,int data){
        if (root==NULL)
        {
            Node* node1 = new Node(data);
            root = node1;
            return root;
        }
        else if(data > root->val){
            root->right = createBST(root->right,data);
        }
        else if(data < root->val){
            root->left = createBST(root->left,data);
        }
        


    }
    void getdata(Node* &root){
        int data;
        cout<<"Enter data value: ";
        cin>>data;
        while (data!=-1)
        {
            root = createBST(root,data);
            cin>>data;
        }
        
    }

   void level_order_traversal(Node* root) {
    if (root == NULL) return; // Handle empty tree case

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of a level

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl; // Print newline at the end of a level
            if (!q.empty()) {
                q.push(NULL); // Add marker for the next level
            }
        } else {
            cout << front->val << " ";
            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}


};
int main(int argc, char const *argv[])
{
    BST obj;
    Node* root = NULL;
    obj.getdata(root);
    obj.level_order_traversal(root);
    return 0;
}
