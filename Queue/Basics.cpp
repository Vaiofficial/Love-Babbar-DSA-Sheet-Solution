#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    
    //push element into the queue
    q.push(45);

    cout << "The size of the queue is : " << q.size() << endl;

    //pop element from the queue
    q.pop();

    if (q.empty())
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << "queue is not empty" << endl;
    }

    q.push(47);
    q.push(48);
    q.push(49);

    //finding front and rear element 
    cout<<"The front element of the queue is :"<<q.front()<<endl;
    cout<<"The rear element of the queue is :"<<q.back()<<endl;



    return 0;
}