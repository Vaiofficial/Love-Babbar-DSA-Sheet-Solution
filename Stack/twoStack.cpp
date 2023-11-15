#include <bits/stdc++.h>
using namespace std;

class twoStack
{

public:
    int *arr;
    int size;
    int top1;
    int top2;

    twoStack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // methods

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "OVERFLOW" << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data)
    {

        if (top2 - top1 == 1)
        {
            cout << "OVERFLOW" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "UNDERFLOW" << endl;
        }
        else
        {
            arr[top1] = 0;
            top1--;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "UNDERFLOW" << endl;
        }
        else
        {
            arr[top2] = 0;
            top2--;
        }
    }

    void print()
    {
        cout << endl;
        cout << "Top 1 : " << top1 << endl;
        cout << "Top 2 : " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    twoStack st(6);
    st.push1(10);
    st.print();
    st.push2(20);
    st.print();
    st.push1(30);
    st.print();
    st.push2(40);
    st.print();
    st.push1(50);
    st.print();
    st.push2(60);
    st.print();
    st.push1(70);
    return 0;
}