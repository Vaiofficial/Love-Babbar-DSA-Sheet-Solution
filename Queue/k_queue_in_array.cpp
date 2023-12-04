#include <bits/stdc++.h>
using namespace std;

class KQueue
{
public:
    int n, k, freeSpot;
    int *arr, *rear, *next, *front;

    KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        // initializing front and rear array with -1
        for (int i = 0; i < k; ++i)
        {
            front[i] = rear[i] = -1;
        }

        // initializing next with i+1 (let kisi element ka next uska just next hi hoga)
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        // handling last index of next array by setting its next to -1 because uska next kuch nahi hoga.
        next[n - 1] = -1;
    }

    bool push(int x, int qi)
    {
        // overflow
        if (freeSpot == -1)
        {
            return false;
        }

        // find the first free index.
        int index = freeSpot;

        // update freespot
        freeSpot = next[index];

        // if first element of Q ith queue
        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // link new element to that q's nearest element
            next[rear[qi]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    int pop(int qi)
    {
        // check for underflow
        if (front[qi] == -1)
        {
            return -1;
        }

        // find index to pop
        int index = front[qi];

        // update front after pop
        front[qi] = next[index];

        // manage free spot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main()
{

    KQueue kq(8, 3);
    cout << kq.push(1, 0) << endl;
    cout << kq.push(2, 0) << endl;
    cout << kq.push(5, 1) << endl;
    cout << kq.push(3, 0) << endl;
    cout << kq.pop(1) << endl;
    cout << kq.pop(0) << endl;
    cout << kq.pop(1) << endl; // underflow case

    return 0;
}