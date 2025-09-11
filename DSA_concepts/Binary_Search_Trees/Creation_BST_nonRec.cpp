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
    Node* root;
    public:
    
    BST(){
        this->root = NULL;
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
        return root;
        


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

Node* maxN(Node* root){
    if(!root){
        return NULL;
    }
    Node* temp = root;
    while (temp->right !=NULL)
    {
        temp = temp->right;
    }
    cout<<"Max value = "<<endl;
    return temp;
    
}

Node* minN(Node* root){
    if(!root){
        return NULL;
    }
    Node* temp = root;
    while (temp->left !=NULL)
    {
        temp = temp->left;
    }
    cout<<"Min value = "<<temp->val<<endl;
    return temp;
    
}

bool searchvalue(Node* &root,int x){
    if (root == NULL)
    {
        return false;
    }
    
    bool left = false;
    bool right = false;
    if(root->val == x){
        return true;
    }
    else if(x > root->val){
        right = searchvalue(root->right,x);
    }
    else{
        left = searchvalue(root->left,x);
    }

    return left || right;
    
}

Node* deleteNode(Node* root, int target){
    if (!root)
    {
        return NULL;
    }

    //solve 1-case

    //search target
    if (root->val == target)
    {
        //case1->leaf node
        if (root->left ==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        

        //case2->left null
        if (root->left ==NULL && root->right!=NULL)
        {
            Node* childtree = root->right;
            delete root;
            return childtree;
        }

        //case3->right null
        if (root->left !=NULL && root->right==NULL)
        {
            Node* childtree = root->left;
            delete root;
            return childtree;
        }

        //case4-> left and right both are non null
        else{

            //get the maximum value from left subtree
           Node* maxi = maxN(root);
            //replace the target with maximum value
           root->val = maxi->val;

           //delete the maximum node from the tree i.e. maxi->value
           root->left = deleteNode(root->left,maxi->val);
           return root;

        }
    }

    //Recursion
    else if(root->val > target){
        root->left = deleteNode(root->left,target);
    }
    else{
        root->right = deleteNode(root->right,target);
    }
    
    return root;
    
}



};
int main(int argc, char const *argv[])
{
    BST obj;
    Node* root = NULL;
    obj.getdata(root);
    obj.level_order_traversal(root);
    int x;
    cout<<"Enter the value to search: ";
    cin>>x;
    while (x!=-2)
    {
        bool ans = obj.searchvalue(root,x);
        if (ans == true)
        {
            cout<<"Value found in tree"<<endl;
            
        }
        else{
            cout<<"Value Not found in tree"<<endl;
            break;
        }
        cin>>x;
    }

    int y;
    cout<<"Enter the value to delete: ";
    cin>>y;
    while (y!=-3)
    {
       obj.deleteNode(root,y);
       cout<<"Value deleted successfully"<<endl;
       obj.level_order_traversal(root);
       cin>>y;
       if(root == NULL){
            cout<<"Nothing to delete"<<endl;
       }
    }
    return 0;
}
