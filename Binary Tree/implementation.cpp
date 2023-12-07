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

// return root node of created tree
Node *createTree()
{
    cout << "enter the value :" << endl;
    int data;
    cin >> data;

    // agar -1 means node ke left ya right mai koi data nahi.
    if (data == -1)
    {
        return NULL;
    }

    // step1 : create a new node
    Node *root = new Node(data);
    // step2 : create left subtree
    cout << "left of Node :" << root->data << endl;
    root->left = createTree();
    // step 3: create right subtree
    cout << "right of Node :" << root->data << endl;
    root->right = createTree();
    return root;

    createTree();
}

// PREORDER TRAVERSAL
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // NLR

    // current node
    cout << root->data << " ";
    // left node
    preOrder(root->left);
    // right node
    preOrder(root->right);
}

// INORDER TRAVERSAL
void inOrder(Node *root)
{
    // LNR
    if (root == NULL)
    {
        return;
    }

    // left node
    inOrder(root->left);
    // print current node
    cout << root->data << " ";
    // right node
    inOrder(root->right);
}

// POSTORDER TRAVERSAL

void postOrder(Node *root)
{
    // LRN

    if (root == NULL)
    {
        return;
    }

    // left node traversal
    postOrder(root->left);
    // right node traversal
    postOrder(root->right);
    // current node print
    cout << root->data << " ";
}

// LEVEL ORDER TRAVERSAL

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            q.push(NULL);
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
    Node *root = createTree();
    cout << "the root node is :" << root->data << endl;

    cout << endl
         << "The Preorder Traversal is :" << endl;
    preOrder(root);
    cout << endl
         << "The Inorder Traversal is :" << endl;
    inOrder(root);
    cout << endl
         << "The Postorder Traversal is :" << endl;
    postOrder(root);
    cout << endl
         << "The Level Order Traversal is :" << endl;
    levelOrder(root);

    return 0;
}