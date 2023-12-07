#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children; // Use a vector to store child nodes

    Node(int val)
    {
        this->data = val;
    }
};

// return root node of created tree
Node *createTree()
{
    cout << "Enter the value:" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Number of children for Node " << root->data << ": ";
    int numChildren;
    cin >> numChildren;

    for (int i = 0; i < numChildren; ++i)
    {
        cout << "Child " << i + 1 << " of Node " << root->data << ":" << endl;
        root->children.push_back(createTree());
    }

    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    for (Node *child : root->children)
    {
        preOrder(child);
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    for (Node *child : root->children)
    {
        inOrder(child);
    }

    cout << root->data << " ";
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    for (Node *child : root->children)
    {
        postOrder(child);
    }

    cout << root->data << " ";
}

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

            for (Node *child : front->children)
            {
                q.push(child);
            }
        }
    }
}

int main()
{
    Node *root = createTree();
    cout << "The root node is: " << root->data << endl;

    cout << endl
         << "The Preorder Traversal is:" << endl;
    preOrder(root);

    cout << endl
         << "The Inorder Traversal is:" << endl;
    inOrder(root);

    cout << endl
         << "The Postorder Traversal is:" << endl;
    postOrder(root);

    cout << endl
         << "The Level Order Traversal is:" << endl;
    levelOrder(root);

    return 0;
}
