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
};

// function to find index in inorder list using map technique
int mapIndex(int inOrder[], int size, map<int, int> &valueToIndex)
{
    for (int i = 0; i < size; i++)
    {
        int element = inOrder[i];
        int index = i;
        valueToIndex[element] = index;
    }
}

Node *constructTreefromPostInOrder(int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size, map<int, int> &valueToIndexMap)
{
    // base case
    if ((postIndex < 0) || (inOrderStart > inOrderEnd))
    {
        return NULL;
    }

    // first case solve kar rha hu
    int element = postOrder[postIndex];
    postIndex--;
    Node *root = new Node(element);

    int position = valueToIndexMap[element]; // using map index f=search kar rhe hai , complexity improve hori hai.(LRN)

    // ab baki recursion samhaal lega - but yha phle right ki call aaygi then left ki call , yehi yaha dhyaan rakhna hai.
    root->right = constructTreefromPostInOrder(postOrder, inOrder, postIndex, position + 1, inOrderEnd, size, valueToIndexMap);
    root->left = constructTreefromPostInOrder(postOrder, inOrder, postIndex, inOrderStart, position - 1, size, valueToIndexMap);

    return root;
}

int main()
{
    int inorder[] = {8, 14, 6, 2, 4, 10};
    int postOrder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int, int> valueToIndexMap;
    // inorder ki elements ki mapping karwa rhe hai.
    mapIndex(inorder, size, valueToIndexMap);

    Node *root = constructTreefromPostInOrder(postOrder, inorder, postIndex, inOrderStart, inOrderEnd, size, valueToIndexMap);
    cout << "Printing the entire tree:" << endl;

    levelOrder(root);

    return 0;
}