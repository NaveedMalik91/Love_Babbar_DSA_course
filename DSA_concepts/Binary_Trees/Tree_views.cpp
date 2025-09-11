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

    // Left view of tree
    void Print_left_view(Node *root, vector<int> &v, int level)
    {
        int size = v.size();
        if (root == NULL)
        {
            return;
        }

        // if level and size of vector is same so push the root data
        // which will be our left node. in right node case the level become greater than size
        if (level == size)
        {
            v.push_back(root->data);
        }

        // call recursivels on left and right subtree
        Print_left_view(root->left, v, level + 1);
        Print_left_view(root->right, v, level + 1);
    }

    void Print_right_view(Node *root, vector<int> &v, int level)
    {
        int size = v.size();
        if (root == NULL)
        {
            return;
        }

        // if level and size of vector is same so push the root data
        // which will be our right node.
        // In right node case the recursive call will be for right subtree first
        if (level == size)
        {
            v.push_back(root->data);
        }

        // call recursivels on left and right subtree
        Print_right_view(root->right, v, level + 1);
        Print_right_view(root->left, v, level + 1);
    }

    void topview(Node *root)
    {
        // create a map to store the mapping of levels corresponding to values
        map<int, int> mp;

        // creat a pair to store the node and corresponding level to check with map
        queue<pair<Node *, int>> q;

        // push root and its level
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            // take the front node of queue which will be in the form of pair
            pair<Node *, int> temp = q.front();
            q.pop();

            // extract the front node
            Node *front = temp.first;
            int level = temp.second;

            // agr level ke liye ans store nahi hua hai toh store krlo
            if (mp.find(level) == mp.end()) // yeh show kr raha hai nahi mili entry
            {
                // store krlo
                mp[level] = front->data;
            }

            // agr child exist krte hai toh push krdo
            if (front->left != NULL)
            {
                q.push(make_pair(front->left, level - 1));
            }

            if (front->right != NULL)
            {
                q.push(make_pair(front->right, level + 1));
            }
        }

        // Printing the top view
        for (auto i : mp)
        {
            cout << i.second << " ";
        }
        cout << endl;
    }

    void bottom_view(Node *root)
    {
        map<int, int> mp;
        queue<pair<Node *, int>> q;

        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            Node *front = temp.first;
            int level = temp.second;

            // push the nodes or update previous at this level inmap
            
            mp[level] = front->data;
            
            if (front->left != NULL)
            {
                q.push(make_pair(front->left,level-1));
            }
            if (front->right != NULL)
            {
                q.push(make_pair(front->right,level+1));
            }
        }

        //print
        for(auto i:mp){
            cout<<i.second<<" ";
        }
        cout<<endl;
    }

    Node *getroot()
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
    

    int level = 0;
    vector<int> v1;
    vector<int> v2;

    obj.Print_left_view(obj.getroot(), v1, level);
    cout << "Printing left view: ";
    for (auto val : v1)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "Printing right view: ";
    obj.Print_right_view(obj.getroot(), v2, level);
    for (auto val : v2)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "Printing Top view: ";
    obj.topview(obj.getroot());

    cout << endl;
    cout << "Printing bottom view: ";
    obj.bottom_view(obj.getroot());

    return 0;
}