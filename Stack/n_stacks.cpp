#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *a, *top, *next;
    int n;
    int size;
    int freeSpot;

public:
    NStack(int _n, int _s) : n(_n), size(_s)
    {
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }

        next[size - 1] = -1;
    }

    bool push(int X, int m)
    {
        if (freeSpot == -1)
        {
            return false;
        }

        // find index;
        int index = freeSpot;

        // update freespot
        freeSpot = next[index];

        // insert in the main array
        a[index] = X;

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // pop from mth stack
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        //pop karne vale element ko is variable mai store kar rhe so that we can return it!!
        int poppedElement = a[index]; 
        next[index] = freeSpot;
        freeSpot = index;
        return poppedElement;
    }

    ~NStack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

int main()
{

    NStack s(3, 6);
    cout << s.push(10, 1) << endl;
    cout << s.push(20, 2) << endl;
    cout << s.push(30, 3) << endl;
    cout<< s.pop(1)<<endl;
    // cout << s.pop(1) << endl;

    return 0;
}