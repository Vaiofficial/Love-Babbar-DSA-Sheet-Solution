#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertNewData(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // agr new node ka value chota hai current node se vo left mai jyga and vice versa for right.
    if (data < root->data)
    {
        root->left = insertNewData(root->left, data);
    }
    else
    {
        root->right = insertNewData(root->right, data);
    }

    return root;
}

void createBinaryTree(Node *&root)
{
    int data;
    cout << "Enter value:" << endl;
    cin >> data;

    while (data != -1)
    {
        root = insertNewData(root, data);
        cout << "Enter the value" << endl;
        cin >> data;
    }
}

void levelOrderTraverse(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    createBinaryTree(root);
    cout<<"The level order traversal is :"<<endl;
    levelOrderTraverse(root);

    return 0;
}