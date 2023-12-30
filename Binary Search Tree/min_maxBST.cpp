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

// sabse left most element minimum hota hai BST mai and vice versa for maximum.
Node *BSTmin(Node *root)
{
    Node *temp = root;

    if (temp == NULL)
    {
        return NULL;
    }

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *BSTmax(Node *root)
{
    Node *temp = root;

    if (temp == NULL)
    {
        return NULL;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

bool searchTarget(Node *root, int targetValue)
{

    // 1. node node se target value ko compare karenge.
    // 2. agar target value greater hua root se to phir bas root ke right mai hi search karenge.
    // 3. agar target value smaller hua to sirf root ke bas left mai hi find out karenge.
    // 4. recursively karnege, ak case mai karunga and rest recursion handle kar lega.
    // 5. agar tree ke left most ya phir right most part mai pahuch gye aur null mil gya means hmko tagret nhi mila end tk  return false kro.

    if (root == NULL)
    {
        return false;
    }

    if (root->data == targetValue)
    {
        return true;
    }

    if (targetValue < root->data)
    {
        // left mai ab bas search karna h
        searchTarget(root->left, targetValue);
    }
    else
    {
        searchTarget(root->right, targetValue);
    }
}

int main()
{
    Node *root = NULL;
    createBinaryTree(root);
    cout << "The level order traversal is :" << endl;
    levelOrderTraverse(root);
    Node *mini = BSTmin(root);
    Node *maxi = BSTmax(root);
    cout << endl
         << "the minimum element of the BST Tree is :" << mini->data;
    cout << endl
         << "the maximum element of the BST Tree is : " << maxi->data<<endl;

    bool presentElement = searchTarget(root, 50);

    if (presentElement == true)
    {
        cout << "the target value is present in the tree" << endl;
    }
    else
    {
        cout << "the target value is not present in the tree" << endl;
    }
    // 50 30 40 20 60 55 70 80 25

    return 0;
}