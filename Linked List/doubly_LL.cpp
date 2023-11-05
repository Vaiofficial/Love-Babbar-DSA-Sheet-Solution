#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    // constrctor

    Node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        cout << "distructor is called for " << this->data << endl;
    }
};

void printNode(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int findLength(Node *head)
{
    int length = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // LL is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode; // yaha galti hogi dhayan dena hai.
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        // create a new node
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{

    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        int length = findLength(head);
        if (position == 1)
        {
            insertAtHead(head, tail, data);
        }
        else if (position == length + 1)
        {
            insertAtTail(head, tail, data);
        }
        else
        {
            // create a node
            Node *newNode = new Node(data);
            Node *currNode = head;
            Node *prevNode = NULL;
            while (position != 1)
            {
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            prevNode->next = newNode;
            newNode->next = currNode;
            newNode->prev = prevNode;
            currNode->prev = newNode;
        }
    }
}

void deleteNode(Node *&head, Node *&tail, int position)
{

    int length = findLength(head);

    if (length == 0)
    {
        cout << "cannot delete , Linked List is empty" << endl;
    }

    // jab single element ho
    if (tail == head)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if (position == length)
    {
        Node *prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode; // yehi pass baar baar galti ho rha h vaibhav , mai baar baar prevNode = tail likh de rha hu! so take care broooo.
    }

    else
    {
        Node *curr = head;
        Node *prev = NULL;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--; // yaha galti ho rhi hai vaibhav bar baar so take caree.....
        }

        Node *newNode = curr->next;

        prev->next = newNode;
        curr->prev = NULL;
        newNode->prev = NULL;
        delete curr;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtHead(head, tail, 100);
    insertAtPosition(head, tail, 1000, 3);

    printNode(head);
    cout << endl;

    deleteNode(head, tail, 1);
    printNode(head);
    cout << endl;

    deleteNode(head, tail, 1);
    printNode(head);
    cout << endl;

    deleteNode(head, tail, 1);
    printNode(head);
    cout << endl;

    deleteNode(head, tail, 1);
    printNode(head);

    deleteNode(head, tail, 1);
    printNode(head);

    return 0;
}