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
        // overflow case.( ye condition mai galti hoti hai)

        if ((rear == size - 1 && front == 0) || (rear == front - 1))
        {
            cout << "overflow" << endl;
        }
        // empty case.(log ye case hi bhul jate hai likhna)
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = data;
        }
        // circular case
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

    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "underflow" << endl;
        }
        // single element case
        else if (rear == front)
        {
            arr[front] = -1;
            rear = -1;
            front = -1;
        }
        // circular case - last se (yha fasenege thoda dhyan dena)
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

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    int getSize()
    {
        return (front == -1 && rear == -1) ? 0 : rear - front + 1;
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
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.pop();
    q.pop();
    q.printQueue();

    return 0;
}