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

Node *CreateBSTfromInorder(int arr[], int size, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    int element = arr[mid];
    Node *root = new Node(element);

    // recursive call

    root->left = CreateBSTfromInorder(arr, size, s, mid - 1);
    root->right = CreateBSTfromInorder(arr, size, mid + 1, e);

    return root;
}

int main()
{
    int arr[] = {10 , 20 , 30 , 40 , 50 , 60 ,70};
    int size = 7;
    int s = 0;
    int e = 6;

    Node *root = CreateBSTfromInorder(arr, size, s, e);

    // Node *root = NULL;
    // createBinaryTree(root);
    cout << "The level order traversal is :" << endl;
    levelOrderTraverse(root);

    return 0;
}