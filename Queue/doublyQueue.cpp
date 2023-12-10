#include <bits/stdc++.h>
using namespace std;

class DQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    DQueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    // pushback

    void pushback(int data)
    {
        // overflow
        if ((rear == size - 1 && front == 0) || (rear == front - 1))
        {
            cout << "Queue Overflow" << endl;
        }
        // emptycase
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = data;
        }
        // circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        // normal case
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    // pushfront

    void pushfront(int data)
    {
        // overflow
        if ((rear == size - 1 && front == 0) || (rear == front - 1))
        {
            cout << "Queue Overflow" << endl;
        }
        // empty case
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[front] = data;
        }
        // circular case
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = data;
        }
        else
        {
            front--;
            arr[front] = data;
        }
    }
    // popfront
    void popfront()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow" << endl;
        }
        // single element
        else if (rear == front)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // circular case
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        // normal case
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    // popback
    void popback()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow" << endl;
        }
        // single element
        else if (rear == front)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // circular case
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        // normal case
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    void printQueue()
    {
        cout << "printing queue :";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DQueue dq(5);
    dq.pushback(20);
    dq.printQueue();
    dq.pushback(40);
    dq.printQueue();
    dq.pushfront(10);
    dq.printQueue();
    dq.pushback(60);
    dq.printQueue();
    dq.pushfront(100);
    dq.printQueue();
    dq.pushback(120); // yaha overflow dega.
    dq.popback();
    dq.printQueue();
    dq.popfront();
    dq.printQueue();
    dq.popback();
    dq.printQueue();
    dq.popfront();
    dq.printQueue();
    dq.popfront();
    dq.printQueue();
    dq.popback(); // yaha underflow aayga.

    return 0;
}