#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
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

    void push(int data)
    {
        if (rear == size - 1)
        {
            cout << "overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "underflow" << endl;
        }

        // empty case when both are -1 , -1
        else if (rear == front)
        {
            arr[front] = -1;
            rear = -1;
            front = -1;
        }
        else
        {
            // normal case
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    int getSize()
    {        
        return (front==-1 && rear==-1) ? 0 : rear - front + 1;
    }

    int getFront()
    {
        if (front == -1)
        {
            cout << "No element in the queue , cannot give front element" << endl;
            return -1;
        }
        else
        {
            return arr[front];
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

    Queue q(5);

    q.printQueue();
    q.push(45);
    q.push(45);
    q.push(45);
    q.push(45);
    q.push(45);
    q.printQueue();
    q.pop();
    q.printQueue();
    q.pop();
    q.printQueue();
    q.pop();
    q.printQueue();
    cout<<"size:"<<q.getSize();

    return 0;
}