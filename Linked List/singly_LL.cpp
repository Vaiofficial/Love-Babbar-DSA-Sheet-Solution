#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        cout << "Consistructor is called" << endl;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // distructor is called
    ~Node()
    {
        cout << "Distructor is called for->" << this->data << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        // step1 - create a new node
        Node *newNode = new Node(data);
        // step 2 - update head and tail.
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step1 - create a new node
        Node *newNode = new Node(data);
        // step 2 - attach new node with head node
        newNode->next = head;
        // update head
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        // step1 - create a new node
        Node *newNode = new Node(data);
        // step 2 - update head and tail.
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step1 - create a new node
        Node *newNode = new Node(data);
        // step 2 - attach new node with tail node
        tail->next = newNode;
        // update tail
        tail = newNode;
    }
}

int printlength(Node *head)
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

void printNode(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->"
             << " ";
        temp = temp->next;
    }
}

void createTail(Node *&head, Node *&tail)
{
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp; // jab loop khatam hui and temp vala pointer khada hoga last vale node par tab usko hum update kar denge.
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    int length = printlength(head);

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
        Node *curr = head;
        Node *prev = NULL;
        // step 1 - create a new node.
        Node *newNode = new Node(data);
        // traverse the linked list and reach to the given position.
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        // step 3 - attach karo new node ko prev se and current se.
        prev->next = newNode;
        newNode->next = curr;
    }
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    int length = printlength(head);

    if (head == tail) //THIS IS TO HANDLE THE HEAD AND TAIL WHEN THERE IS ONLY ONE ELEMENT AND BOTH POINTING TO THAT ELEMENT.
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    // DELETE FROM FIRST POSITION
    if (position == 1)
    {
        // temp create kiye so that we can keep track of head pointer beacuase head ko hum next node se point karenge to first node ka access chale jyga thats whhy first node ko access kar ske is liye temp se point kar diye

        Node *temp = head; 
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    // DELETE LAST ELEMENT
    else if (position == length)
    {
        Node *prev = head;

        while (prev->next != tail) // second last tak pahuchne k liye.
        {
            prev = prev->next;
        }

        // DELINKING THE POINTER
        prev->next = NULL;
        delete tail;
        tail = prev;
    }
    // // DELETE FROM THE MIDDLE OF THE LINKED LIST.
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
};

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    // insertAtTail(head, tail, 20);
    // insertAtTail(head, tail, 30);
    // insertAtTail(head, tail, 40);
    // cout << "printing linked list before insert at any position function call" << endl;
    printNode(head);
    cout<<endl;
    // cout <<"printing linked list after calling insert at any function call" << endl;
    // insertAtPosition(head, tail, position, 1000);
    // printNode(head);
    // cout << endl<< "printing linked list after deletion" << endl;
    deleteNode(head, tail, 1);
    // printNode(head);

    // Node *first = new Node(100);
    // Node *second = new Node(30);
    // Node *third = new Node(20);
    // Node *fourth = new Node(60);
    // Node *fifth = new Node(10);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node *head = first;
    // Node *tail = fifth;

    // cout << "printing the entire linked list" << endl;
    // printNode(head);
    // cout << endl
    //      << "the length of the linked list is : " << printlength(head) << endl;
    // insertAtHead(head, tail, 500);
    // cout << "printing the entire linked list after inserting at the head" << endl;
    // printNode(head);
    // cout << endl
    //      << "the length of the linked list is : " << printlength(head) << endl;
    // insertAtTail(head, tail, 700);
    // cout << "printing the entire linked list after inserting at the end" << endl;
    // printNode(head);
    // cout << endl
    //      << "the length of the linked list is : " << printlength(head) << endl;

    return 0;
}