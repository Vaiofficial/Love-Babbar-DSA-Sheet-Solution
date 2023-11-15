#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    // constructor call
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {

        if (top == size - 1)
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
        }
        else
            top--;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
            return arr[top];
    }

    int getSize()
    {
        return top + 1;
    }

    void print()
    {
        cout << "Top :" << top << endl;
        cout << "Top Element :" << getTop() << endl;
        cout << "Stack :" << endl;
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack st(4);

    st.push(5);
    st.push(10);
    st.push(2);
    st.push(4);
    st.print();
    
    cout<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.print();
    if(st.isEmpty())
    {
        cout<<"stack is empty..."<<endl;
    }
    st.pop();
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    return 0;
}